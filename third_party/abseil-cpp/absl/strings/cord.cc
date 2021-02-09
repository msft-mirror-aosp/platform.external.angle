// Copyright 2020 The Abseil Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "absl/strings/cord.h"

#include <algorithm>
#include <atomic>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <type_traits>
#include <unordered_set>
#include <vector>

#include "absl/base/casts.h"
#include "absl/base/internal/raw_logging.h"
#include "absl/base/macros.h"
#include "absl/base/port.h"
#include "absl/container/fixed_array.h"
#include "absl/container/inlined_vector.h"
#include "absl/strings/escaping.h"
#include "absl/strings/internal/cord_internal.h"
#include "absl/strings/internal/cord_rep_flat.h"
#include "absl/strings/internal/cord_rep_ring.h"
#include "absl/strings/internal/resize_uninitialized.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_format.h"
#include "absl/strings/str_join.h"
#include "absl/strings/string_view.h"

namespace absl {
ABSL_NAMESPACE_BEGIN

using ::absl::cord_internal::CordRep;
using ::absl::cord_internal::CordRepConcat;
using ::absl::cord_internal::CordRepExternal;
using ::absl::cord_internal::CordRepFlat;
using ::absl::cord_internal::CordRepRing;
using ::absl::cord_internal::CordRepSubstring;
using ::absl::cord_internal::kMinFlatLength;
using ::absl::cord_internal::kMaxFlatLength;

using ::absl::cord_internal::CONCAT;
using ::absl::cord_internal::EXTERNAL;
using ::absl::cord_internal::FLAT;
using ::absl::cord_internal::RING;
using ::absl::cord_internal::SUBSTRING;

using ::absl::cord_internal::kInlinedVectorSize;
using ::absl::cord_internal::kMaxBytesToCopy;

constexpr uint64_t Fibonacci(unsigned char n, uint64_t a = 0, uint64_t b = 1) {
  return n == 0 ? a : Fibonacci(n - 1, b, a + b);
}

static_assert(Fibonacci(63) == 6557470319842,
              "Fibonacci values computed incorrectly");

// Minimum length required for a given depth tree -- a tree is considered
// balanced if
//      length(t) >= min_length[depth(t)]
// The root node depth is allowed to become twice as large to reduce rebalancing
// for larger strings (see IsRootBalanced).
static constexpr uint64_t min_length[] = {
    Fibonacci(2),          Fibonacci(3),  Fibonacci(4),  Fibonacci(5),
    Fibonacci(6),          Fibonacci(7),  Fibonacci(8),  Fibonacci(9),
    Fibonacci(10),         Fibonacci(11), Fibonacci(12), Fibonacci(13),
    Fibonacci(14),         Fibonacci(15), Fibonacci(16), Fibonacci(17),
    Fibonacci(18),         Fibonacci(19), Fibonacci(20), Fibonacci(21),
    Fibonacci(22),         Fibonacci(23), Fibonacci(24), Fibonacci(25),
    Fibonacci(26),         Fibonacci(27), Fibonacci(28), Fibonacci(29),
    Fibonacci(30),         Fibonacci(31), Fibonacci(32), Fibonacci(33),
    Fibonacci(34),         Fibonacci(35), Fibonacci(36), Fibonacci(37),
    Fibonacci(38),         Fibonacci(39), Fibonacci(40), Fibonacci(41),
    Fibonacci(42),         Fibonacci(43), Fibonacci(44), Fibonacci(45),
    Fibonacci(46),         Fibonacci(47),
    0xffffffffffffffffull,  // Avoid overflow
};

static const int kMinLengthSize = ABSL_ARRAYSIZE(min_length);

static inline bool cord_ring_enabled() {
  return cord_internal::cord_ring_buffer_enabled.load(
      std::memory_order_relaxed);
}

static inline bool IsRootBalanced(CordRep* node) {
  if (node->tag != CONCAT) {
    return true;
  } else if (node->concat()->depth() <= 15) {
    return true;
  } else if (node->concat()->depth() > kMinLengthSize) {
    return false;
  } else {
    // Allow depth to become twice as large as implied by fibonacci rule to
    // reduce rebalancing for larger strings.
    return (node->length >= min_length[node->concat()->depth() / 2]);
  }
}

static CordRep* Rebalance(CordRep* node);
static void DumpNode(CordRep* rep, bool include_data, std::ostream* os,
                     int indent = 0);
static bool VerifyNode(CordRep* root, CordRep* start_node,
                       bool full_validation);

static inline CordRep* VerifyTree(CordRep* node) {
  // Verification is expensive, so only do it in debug mode.
  // Even in debug mode we normally do only light validation.
  // If you are debugging Cord itself, you should define the
  // macro EXTRA_CORD_VALIDATION, e.g. by adding
  // --copt=-DEXTRA_CORD_VALIDATION to the blaze line.
#ifdef EXTRA_CORD_VALIDATION
  assert(node == nullptr || VerifyNode(node, node, /*full_validation=*/true));
#else   // EXTRA_CORD_VALIDATION
  assert(node == nullptr || VerifyNode(node, node, /*full_validation=*/false));
#endif  // EXTRA_CORD_VALIDATION
  static_cast<void>(&VerifyNode);

  return node;
}

// Return the depth of a node
static int Depth(const CordRep* rep) {
  if (rep->tag == CONCAT) {
    return rep->concat()->depth();
  } else {
    return 0;
  }
}

static void SetConcatChildren(CordRepConcat* concat, CordRep* left,
                              CordRep* right) {
  concat->left = left;
  concat->right = right;

  concat->length = left->length + right->length;
  concat->set_depth(1 + std::max(Depth(left), Depth(right)));
}

// Create a concatenation of the specified nodes.
// Does not change the refcounts of "left" and "right".
// The returned node has a refcount of 1.
static CordRep* RawConcat(CordRep* left, CordRep* right) {
  // Avoid making degenerate concat nodes (one child is empty)
  if (left == nullptr) return right;
  if (right == nullptr) return left;
  if (left->length == 0) {
    CordRep::Unref(left);
    return right;
  }
  if (right->length == 0) {
    CordRep::Unref(right);
    return left;
  }

  CordRepConcat* rep = new CordRepConcat();
  rep->tag = CONCAT;
  SetConcatChildren(rep, left, right);

  return rep;
}

static CordRep* Concat(CordRep* left, CordRep* right) {
  CordRep* rep = RawConcat(left, right);
  if (rep != nullptr && !IsRootBalanced(rep)) {
    rep = Rebalance(rep);
  }
  return VerifyTree(rep);
}

// Make a balanced tree out of an array of leaf nodes.
static CordRep* MakeBalancedTree(CordRep** reps, size_t n) {
  // Make repeated passes over the array, merging adjacent pairs
  // until we are left with just a single node.
  while (n > 1) {
    size_t dst = 0;
    for (size_t src = 0; src < n; src += 2) {
      if (src + 1 < n) {
        reps[dst] = Concat(reps[src], reps[src + 1]);
      } else {
        reps[dst] = reps[src];
      }
      dst++;
    }
    n = dst;
  }

  return reps[0];
}

static CordRepFlat* CreateFlat(const char* data, size_t length,
                            size_t alloc_hint) {
  CordRepFlat* flat = CordRepFlat::New(length + alloc_hint);
  flat->length = length;
  memcpy(flat->Data(), data, length);
  return flat;
}

// Creates a new flat or ringbuffer out of the specified array.
// The returned node has a refcount of 1.
static CordRep* RingNewTree(const char* data, size_t length,
                            size_t alloc_hint) {
  if (length <= kMaxFlatLength) {
    return CreateFlat(data, length, alloc_hint);
  }
  CordRepFlat* flat = CreateFlat(data, kMaxFlatLength, 0);
  data += kMaxFlatLength;
  length -= kMaxFlatLength;
  size_t extra = (length - 1) / kMaxFlatLength + 1;
  auto* root = CordRepRing::Create(flat, extra);
  return CordRepRing::Append(root, {data, length}, alloc_hint);
}

// Create a new tree out of the specified array.
// The returned node has a refcount of 1.
static CordRep* NewTree(const char* data,
                        size_t length,
                        size_t alloc_hint) {
  if (length == 0) return nullptr;
  if (cord_ring_enabled()) {
    return RingNewTree(data, length, alloc_hint);
  }
  absl::FixedArray<CordRep*> reps((length - 1) / kMaxFlatLength + 1);
  size_t n = 0;
  do {
    const size_t len = std::min(length, kMaxFlatLength);
    CordRepFlat* rep = CordRepFlat::New(len + alloc_hint);
    rep->length = len;
    memcpy(rep->Data(), data, len);
    reps[n++] = VerifyTree(rep);
    data += len;
    length -= len;
  } while (length != 0);
  return MakeBalancedTree(reps.data(), n);
}

namespace cord_internal {

void InitializeCordRepExternal(absl::string_view data, CordRepExternal* rep) {
  assert(!data.empty());
  rep->length = data.size();
  rep->tag = EXTERNAL;
  rep->base = data.data();
  VerifyTree(rep);
}

}  // namespace cord_internal

static CordRep* NewSubstring(CordRep* child, size_t offset, size_t length) {
  // Never create empty substring nodes
  if (length == 0) {
    CordRep::Unref(child);
    return nullptr;
  } else {
    CordRepSubstring* rep = new CordRepSubstring();
    assert((offset + length) <= child->length);
    rep->length = length;
    rep->tag = SUBSTRING;
    rep->start = offset;
    rep->child = child;
    return VerifyTree(rep);
  }
}

// --------------------------------------------------------------------
// Cord::InlineRep functions

constexpr unsigned char Cord::InlineRep::kMaxInline;

inline void Cord::InlineRep::set_data(const char* data, size_t n,
                                      bool nullify_tail) {
  static_assert(kMaxInline == 15, "set_data is hard-coded for a length of 15");

  cord_internal::SmallMemmove(data_.as_chars(), data, n, nullify_tail);
  set_inline_size(n);
}

inline char* Cord::InlineRep::set_data(size_t n) {
  assert(n <= kMaxInline);
  ResetToEmpty();
  set_inline_size(n);
  return data_.as_chars();
}

inline CordRep* Cord::InlineRep::force_tree(size_t extra_hint) {
  if (data_.is_tree()) {
    return data_.as_tree();
  }

  size_t len = inline_size();
  CordRepFlat* result = CordRepFlat::New(len + extra_hint);
  result->length = len;
  static_assert(kMinFlatLength >= sizeof(data_), "");
  memcpy(result->Data(), data_.as_chars(), sizeof(data_));
  set_tree(result);
  return result;
}

inline void Cord::InlineRep::reduce_size(size_t n) {
  size_t tag = inline_size();
  assert(tag <= kMaxInline);
  assert(tag >= n);
  tag -= n;
  memset(data_.as_chars() + tag, 0, n);
  set_inline_size(static_cast<char>(tag));
}

inline void Cord::InlineRep::remove_prefix(size_t n) {
  cord_internal::SmallMemmove(data_.as_chars(), data_.as_chars() + n,
                              inline_size() - n);
  reduce_size(n);
}

// Returns `rep` converted into a CordRepRing.
// Directly returns `rep` if `rep` is already a CordRepRing.
static CordRepRing* ForceRing(CordRep* rep, size_t extra) {
  return (rep->tag == RING) ? rep->ring() : CordRepRing::Create(rep, extra);
}

void Cord::InlineRep::AppendTree(CordRep* tree) {
  if (tree == nullptr) return;
  if (data_.is_empty()) {
    set_tree(tree);
  } else if (cord_ring_enabled()) {
    set_tree(CordRepRing::Append(ForceRing(force_tree(0), 1), tree));
  } else {
    set_tree(Concat(force_tree(0), tree));
  }
}

void Cord::InlineRep::PrependTree(CordRep* tree) {
  assert(tree != nullptr);
  if (data_.is_empty()) {
    set_tree(tree);
  } else if (cord_ring_enabled()) {
    set_tree(CordRepRing::Prepend(ForceRing(force_tree(0), 1), tree));
  } else {
    set_tree(Concat(tree, force_tree(0)));
  }
}

// Searches for a non-full flat node at the rightmost leaf of the tree. If a
// suitable leaf is found, the function will update the length field for all
// nodes to account for the size increase. The append region address will be
// written to region and the actual size increase will be written to size.
static inline bool PrepareAppendRegion(CordRep* root, char** region,
                                       size_t* size, size_t max_length) {
  if (root->tag == RING && root->refcount.IsOne()) {
    Span<char> span = root->ring()->GetAppendBuffer(max_length);
    if (!span.empty()) {
      *region = span.data();
      *size = span.size();
      return true;
    }
  }

  // Search down the right-hand path for a non-full FLAT node.
  CordRep* dst = root;
  while (dst->tag == CONCAT && dst->refcount.IsOne()) {
    dst = dst->concat()->right;
  }

  if (dst->tag < FLAT || !dst->refcount.IsOne()) {
    *region = nullptr;
    *size = 0;
    return false;
  }

  const size_t in_use = dst->length;
  const size_t capacity = dst->flat()->Capacity();
  if (in_use == capacity) {
    *region = nullptr;
    *size = 0;
    return false;
  }

  size_t size_increase = std::min(capacity - in_use, max_length);

  // We need to update the length fields for all nodes, including the leaf node.
  for (CordRep* rep = root; rep != dst; rep = rep->concat()->right) {
    rep->length += size_increase;
  }
  dst->length += size_increase;

  *region = dst->flat()->Data() + in_use;
  *size = size_increase;
  return true;
}

void Cord::InlineRep::GetAppendRegion(char** region, size_t* size,
                                      size_t max_length) {
  if (max_length == 0) {
    *region = nullptr;
    *size = 0;
    return;
  }

  // Try to fit in the inline buffer if possible.
  if (!is_tree()) {
    size_t inline_length = inline_size();
    if (max_length <= kMaxInline - inline_length) {
      *region = data_.as_chars() + inline_length;
      *size = max_length;
      set_inline_size(inline_length + max_length);
      return;
    }
  }

  CordRep* root = force_tree(max_length);

  if (PrepareAppendRegion(root, region, size, max_length)) {
    return;
  }

  // Allocate new node.
  CordRepFlat* new_node =
      CordRepFlat::New(std::max(static_cast<size_t>(root->length), max_length));
  new_node->length = std::min(new_node->Capacity(), max_length);
  *region = new_node->Data();
  *size = new_node->length;

  if (cord_ring_enabled()) {
    replace_tree(CordRepRing::Append(ForceRing(root, 1), new_node));
    return;
  }
  replace_tree(Concat(root, new_node));
}

void Cord::InlineRep::GetAppendRegion(char** region, size_t* size) {
  const size_t max_length = std::numeric_limits<size_t>::max();

  // Try to fit in the inline buffer if possible.
  if (!data_.is_tree()) {
    size_t inline_length = inline_size();
    if (inline_length < kMaxInline) {
      *region = data_.as_chars() + inline_length;
      *size = kMaxInline - inline_length;
      set_inline_size(kMaxInline);
      return;
    }
  }

  CordRep* root = force_tree(max_length);

  if (PrepareAppendRegion(root, region, size, max_length)) {
    return;
  }

  // Allocate new node.
  CordRepFlat* new_node = CordRepFlat::New(root->length);
  new_node->length = new_node->Capacity();
  *region = new_node->Data();
  *size = new_node->length;

  if (cord_ring_enabled()) {
    replace_tree(CordRepRing::Append(ForceRing(root, 1), new_node));
    return;
  }
  replace_tree(Concat(root, new_node));
}

// If the rep is a leaf, this will increment the value at total_mem_usage and
// will return true.
static bool RepMemoryUsageLeaf(const CordRep* rep, size_t* total_mem_usage) {
  if (rep->tag >= FLAT) {
    *total_mem_usage += rep->flat()->AllocatedSize();
    return true;
  }
  if (rep->tag == EXTERNAL) {
    *total_mem_usage += sizeof(CordRepConcat) + rep->length;
    return true;
  }
  return false;
}

void Cord::InlineRep::AssignSlow(const Cord::InlineRep& src) {
  ClearSlow();

  data_ = src.data_;
  if (is_tree()) {
    CordRep::Ref(tree());
  }
}

void Cord::InlineRep::ClearSlow() {
  if (is_tree()) {
    CordRep::Unref(tree());
  }
  ResetToEmpty();
}

// --------------------------------------------------------------------
// Constructors and destructors

Cord::Cord(const Cord& src) : contents_(src.contents_) {
  if (CordRep* tree = contents_.tree()) {
    CordRep::Ref(tree);
  }
}

Cord::Cord(absl::string_view src) {
  const size_t n = src.size();
  if (n <= InlineRep::kMaxInline) {
    contents_.set_data(src.data(), n, false);
  } else {
    contents_.set_tree(NewTree(src.data(), n, 0));
  }
}

template <typename T, Cord::EnableIfString<T>>
Cord::Cord(T&& src) {
  if (
      // String is short: copy data to avoid external block overhead.
      src.size() <= kMaxBytesToCopy ||
      // String is wasteful: copy data to avoid pinning too much unused memory.
      src.size() < src.capacity() / 2
  ) {
    if (src.size() <= InlineRep::kMaxInline) {
      contents_.set_data(src.data(), src.size(), false);
    } else {
      contents_.set_tree(NewTree(src.data(), src.size(), 0));
    }
  } else {
    struct StringReleaser {
      void operator()(absl::string_view /* data */) {}
      std::string data;
    };
    const absl::string_view original_data = src;
    auto* rep = static_cast<
        ::absl::cord_internal::CordRepExternalImpl<StringReleaser>*>(
        absl::cord_internal::NewExternalRep(
            original_data, StringReleaser{std::forward<T>(src)}));
    // Moving src may have invalidated its data pointer, so adjust it.
    rep->base = rep->template get<0>().data.data();
    contents_.set_tree(rep);
  }
}

template Cord::Cord(std::string&& src);

// The destruction code is separate so that the compiler can determine
// that it does not need to call the destructor on a moved-from Cord.
void Cord::DestroyCordSlow() {
  if (CordRep* tree = contents_.tree()) {
    CordRep::Unref(VerifyTree(tree));
  }
}

// --------------------------------------------------------------------
// Mutators

void Cord::Clear() {
  if (CordRep* tree = contents_.clear()) {
    CordRep::Unref(tree);
  }
}

Cord& Cord::operator=(absl::string_view src) {

  const char* data = src.data();
  size_t length = src.size();
  CordRep* tree = contents_.tree();
  if (length <= InlineRep::kMaxInline) {
    // Embed into this->contents_
    contents_.set_data(data, length, true);
    if (tree) CordRep::Unref(tree);
    return *this;
  }
  if (tree != nullptr && tree->tag >= FLAT &&
      tree->flat()->Capacity() >= length &&
      tree->refcount.IsOne()) {
    // Copy in place if the existing FLAT node is reusable.
    memmove(tree->flat()->Data(), data, length);
    tree->length = length;
    VerifyTree(tree);
    return *this;
  }
  contents_.set_tree(NewTree(data, length, 0));
  if (tree) CordRep::Unref(tree);
  return *this;
}

template <typename T, Cord::EnableIfString<T>>
Cord& Cord::operator=(T&& src) {
  if (src.size() <= kMaxBytesToCopy) {
    *this = absl::string_view(src);
  } else {
    *this = Cord(std::forward<T>(src));
  }
  return *this;
}

template Cord& Cord::operator=(std::string&& src);

// TODO(sanjay): Move to Cord::InlineRep section of file.  For now,
// we keep it here to make diffs easier.
void Cord::InlineRep::AppendArray(const char* src_data, size_t src_size) {
  if (src_size == 0) return;  // memcpy(_, nullptr, 0) is undefined.

  size_t appended = 0;
  CordRep* root = nullptr;
  if (is_tree()) {
    root = data_.as_tree();
    char* region;
    if (PrepareAppendRegion(root, &region, &appended, src_size)) {
      memcpy(region, src_data, appended);
    }
  } else {
    // Try to fit in the inline buffer if possible.
    size_t inline_length = inline_size();
    if (src_size <= kMaxInline - inline_length) {
      // Append new data to embedded array
      memcpy(data_.as_chars() + inline_length, src_data, src_size);
      set_inline_size(inline_length + src_size);
      return;
    }

    // It is possible that src_data == data_, but when we transition from an
    // InlineRep to a tree we need to assign data_ = root via set_tree. To
    // avoid corrupting the source data before we copy it, delay calling
    // set_tree until after we've copied data.
    // We are going from an inline size to beyond inline size. Make the new size
    // either double the inlined size, or the added size + 10%.
    const size_t size1 = inline_length * 2 + src_size;
    const size_t size2 = inline_length + src_size / 10;
    root = CordRepFlat::New(std::max<size_t>(size1, size2));
    appended = std::min(
        src_size, root->flat()->Capacity() - inline_length);
    memcpy(root->flat()->Data(), data_.as_chars(), inline_length);
    memcpy(root->flat()->Data() + inline_length, src_data, appended);
    root->length = inline_length + appended;
    set_tree(root);
  }

  src_data += appended;
  src_size -= appended;
  if (src_size == 0) {
    return;
  }

  if (cord_ring_enabled()) {
    absl::string_view data(src_data, src_size);
    root = ForceRing(root, (data.size() - 1) / kMaxFlatLength + 1);
    replace_tree(CordRepRing::Append(root->ring(), data));
    return;
  }

  // Use new block(s) for any remaining bytes that were not handled above.
  // Alloc extra memory only if the right child of the root of the new tree is
  // going to be a FLAT node, which will permit further inplace appends.
  size_t length = src_size;
  if (src_size < kMaxFlatLength) {
    // The new length is either
    // - old size + 10%
    // - old_size + src_size
    // This will cause a reasonable conservative step-up in size that is still
    // large enough to avoid excessive amounts of small fragments being added.
    length = std::max<size_t>(root->length / 10, src_size);
  }
  set_tree(Concat(root, NewTree(src_data, src_size, length - src_size)));
}

inline CordRep* Cord::TakeRep() const& {
  return CordRep::Ref(contents_.tree());
}

inline CordRep* Cord::TakeRep() && {
  CordRep* rep = contents_.tree();
  contents_.clear();
  return rep;
}

template <typename C>
inline void Cord::AppendImpl(C&& src) {
  if (empty()) {
    // In case of an empty destination avoid allocating a new node, do not copy
    // data.
    *this = std::forward<C>(src);
    return;
  }

  // For short cords, it is faster to copy data if there is room in dst.
  const size_t src_size = src.contents_.size();
  if (src_size <= kMaxBytesToCopy) {
    CordRep* src_tree = src.contents_.tree();
    if (src_tree == nullptr) {
      // src has embedded data.
      contents_.AppendArray(src.contents_.data(), src_size);
      return;
    }
    if (src_tree->tag >= FLAT) {
      // src tree just has one flat node.
      contents_.AppendArray(src_tree->flat()->Data(), src_size);
      return;
    }
    if (&src == this) {
      // ChunkIterator below assumes that src is not modified during traversal.
      Append(Cord(src));
      return;
    }
    // TODO(mec): Should we only do this if "dst" has space?
    for (absl::string_view chunk : src.Chunks()) {
      Append(chunk);
    }
    return;
  }

  // Guaranteed to be a tree (kMaxBytesToCopy > kInlinedSize)
  contents_.AppendTree(std::forward<C>(src).TakeRep());
}

void Cord::Append(const Cord& src) { AppendImpl(src); }

void Cord::Append(Cord&& src) { AppendImpl(std::move(src)); }

template <typename T, Cord::EnableIfString<T>>
void Cord::Append(T&& src) {
  if (src.size() <= kMaxBytesToCopy) {
    Append(absl::string_view(src));
  } else {
    Append(Cord(std::forward<T>(src)));
  }
}

template void Cord::Append(std::string&& src);

void Cord::Prepend(const Cord& src) {
  CordRep* src_tree = src.contents_.tree();
  if (src_tree != nullptr) {
    CordRep::Ref(src_tree);
    contents_.PrependTree(src_tree);
    return;
  }

  // `src` cord is inlined.
  absl::string_view src_contents(src.contents_.data(), src.contents_.size());
  return Prepend(src_contents);
}

void Cord::Prepend(absl::string_view src) {
  if (src.empty()) return;  // memcpy(_, nullptr, 0) is undefined.
  if (!contents_.is_tree()) {
    size_t cur_size = contents_.inline_size();
    if (cur_size + src.size() <= InlineRep::kMaxInline) {
      // Use embedded storage.
      char data[InlineRep::kMaxInline + 1] = {0};
      memcpy(data, src.data(), src.size());
      memcpy(data + src.size(), contents_.data(), cur_size);
      memcpy(contents_.data_.as_chars(), data, InlineRep::kMaxInline + 1);
      contents_.set_inline_size(cur_size + src.size());
      return;
    }
  }
  contents_.PrependTree(NewTree(src.data(), src.size(), 0));
}

template <typename T, Cord::EnableIfString<T>>
inline void Cord::Prepend(T&& src) {
  if (src.size() <= kMaxBytesToCopy) {
    Prepend(absl::string_view(src));
  } else {
    Prepend(Cord(std::forward<T>(src)));
  }
}

template void Cord::Prepend(std::string&& src);

static CordRep* RemovePrefixFrom(CordRep* node, size_t n) {
  if (n >= node->length) return nullptr;
  if (n == 0) return CordRep::Ref(node);
  absl::InlinedVector<CordRep*, kInlinedVectorSize> rhs_stack;

  while (node->tag == CONCAT) {
    assert(n <= node->length);
    if (n < node->concat()->left->length) {
      // Push right to stack, descend left.
      rhs_stack.push_back(node->concat()->right);
      node = node->concat()->left;
    } else {
      // Drop left, descend right.
      n -= node->concat()->left->length;
      node = node->concat()->right;
    }
  }
  assert(n <= node->length);

  if (n == 0) {
    CordRep::Ref(node);
  } else {
    size_t start = n;
    size_t len = node->length - n;
    if (node->tag == SUBSTRING) {
      // Consider in-place update of node, similar to in RemoveSuffixFrom().
      start += node->substring()->start;
      node = node->substring()->child;
    }
    node = NewSubstring(CordRep::Ref(node), start, len);
  }
  while (!rhs_stack.empty()) {
    node = Concat(node, CordRep::Ref(rhs_stack.back()));
    rhs_stack.pop_back();
  }
  return node;
}

// RemoveSuffixFrom() is very similar to RemovePrefixFrom(), with the
// exception that removing a suffix has an optimization where a node may be
// edited in place iff that node and all its ancestors have a refcount of 1.
static CordRep* RemoveSuffixFrom(CordRep* node, size_t n) {
  if (n >= node->length) return nullptr;
  if (n == 0) return CordRep::Ref(node);
  absl::InlinedVector<CordRep*, kInlinedVectorSize> lhs_stack;
  bool inplace_ok = node->refcount.IsOne();

  while (node->tag == CONCAT) {
    assert(n <= node->length);
    if (n < node->concat()->right->length) {
      // Push left to stack, descend right.
      lhs_stack.push_back(node->concat()->left);
      node = node->concat()->right;
    } else {
      // Drop right, descend left.
      n -= node->concat()->right->length;
      node = node->concat()->left;
    }
    inplace_ok = inplace_ok && node->refcount.IsOne();
  }
  assert(n <= node->length);

  if (n == 0) {
    CordRep::Ref(node);
  } else if (inplace_ok && node->tag != EXTERNAL) {
    // Consider making a new buffer if the current node capacity is much
    // larger than the new length.
    CordRep::Ref(node);
    node->length -= n;
  } else {
    size_t start = 0;
    size_t len = node->length - n;
    if (node->tag == SUBSTRING) {
      start = node->substring()->start;
      node = node->substring()->child;
    }
    node = NewSubstring(CordRep::Ref(node), start, len);
  }
  while (!lhs_stack.empty()) {
    node = Concat(CordRep::Ref(lhs_stack.back()), node);
    lhs_stack.pop_back();
  }
  return node;
}

void Cord::RemovePrefix(size_t n) {
  ABSL_INTERNAL_CHECK(n <= size(),
                      absl::StrCat("Requested prefix size ", n,
                                   " exceeds Cord's size ", size()));
  CordRep* tree = contents_.tree();
  if (tree == nullptr) {
    contents_.remove_prefix(n);
  } else if (tree->tag == RING) {
    contents_.replace_tree(CordRepRing::RemovePrefix(tree->ring(), n));
  } else {
    CordRep* newrep = RemovePrefixFrom(tree, n);
    CordRep::Unref(tree);
    contents_.replace_tree(VerifyTree(newrep));
  }
}

void Cord::RemoveSuffix(size_t n) {
  ABSL_INTERNAL_CHECK(n <= size(),
                      absl::StrCat("Requested suffix size ", n,
                                   " exceeds Cord's size ", size()));
  CordRep* tree = contents_.tree();
  if (tree == nullptr) {
    contents_.reduce_size(n);
  } else if (tree->tag == RING) {
    contents_.replace_tree(CordRepRing::RemoveSuffix(tree->ring(), n));
  } else {
    CordRep* newrep = RemoveSuffixFrom(tree, n);
    CordRep::Unref(tree);
    contents_.replace_tree(VerifyTree(newrep));
  }
}

// Work item for NewSubRange().
struct SubRange {
  SubRange(CordRep* a_node, size_t a_pos, size_t a_n)
      : node(a_node), pos(a_pos), n(a_n) {}
  CordRep* node;  // nullptr means concat last 2 results.
  size_t pos;
  size_t n;
};

static CordRep* NewSubRange(CordRep* node, size_t pos, size_t n) {
  absl::InlinedVector<CordRep*, kInlinedVectorSize> results;
  absl::InlinedVector<SubRange, kInlinedVectorSize> todo;
  todo.push_back(SubRange(node, pos, n));
  do {
    const SubRange& sr = todo.back();
    node = sr.node;
    pos = sr.pos;
    n = sr.n;
    todo.pop_back();

    if (node == nullptr) {
      assert(results.size() >= 2);
      CordRep* right = results.back();
      results.pop_back();
      CordRep* left = results.back();
      results.pop_back();
      results.push_back(Concat(left, right));
    } else if (pos == 0 && n == node->length) {
      results.push_back(CordRep::Ref(node));
    } else if (node->tag != CONCAT) {
      if (node->tag == SUBSTRING) {
        pos += node->substring()->start;
        node = node->substring()->child;
      }
      results.push_back(NewSubstring(CordRep::Ref(node), pos, n));
    } else if (pos + n <= node->concat()->left->length) {
      todo.push_back(SubRange(node->concat()->left, pos, n));
    } else if (pos >= node->concat()->left->length) {
      pos -= node->concat()->left->length;
      todo.push_back(SubRange(node->concat()->right, pos, n));
    } else {
      size_t left_n = node->concat()->left->length - pos;
      todo.push_back(SubRange(nullptr, 0, 0));  // Concat()
      todo.push_back(SubRange(node->concat()->right, 0, n - left_n));
      todo.push_back(SubRange(node->concat()->left, pos, left_n));
    }
  } while (!todo.empty());
  assert(results.size() == 1);
  return results[0];
}

Cord Cord::Subcord(size_t pos, size_t new_size) const {
  Cord sub_cord;
  size_t length = size();
  if (pos > length) pos = length;
  if (new_size > length - pos) new_size = length - pos;
  CordRep* tree = contents_.tree();
  if (tree == nullptr) {
    // sub_cord is newly constructed, no need to re-zero-out the tail of
    // contents_ memory.
    sub_cord.contents_.set_data(contents_.data() + pos, new_size, false);
  } else if (new_size == 0) {
    // We want to return empty subcord, so nothing to do.
  } else if (new_size <= InlineRep::kMaxInline) {
    Cord::ChunkIterator it = chunk_begin();
    it.AdvanceBytes(pos);
    char* dest = sub_cord.contents_.data_.as_chars();
    size_t remaining_size = new_size;
    while (remaining_size > it->size()) {
      cord_internal::SmallMemmove(dest, it->data(), it->size());
      remaining_size -= it->size();
      dest += it->size();
      ++it;
    }
    cord_internal::SmallMemmove(dest, it->data(), remaining_size);
    sub_cord.contents_.set_inline_size(new_size);
  } else if (tree->tag == RING) {
    tree = CordRepRing::SubRing(CordRep::Ref(tree)->ring(), pos, new_size);
    sub_cord.contents_.set_tree(tree);
  } else {
    sub_cord.contents_.set_tree(NewSubRange(tree, pos, new_size));
  }
  return sub_cord;
}

// --------------------------------------------------------------------
// Balancing

class CordForest {
 public:
  explicit CordForest(size_t length)
      : root_length_(length), trees_(kMinLengthSize, nullptr) {}

  void Build(CordRep* cord_root) {
    std::vector<CordRep*> pending = {cord_root};

    while (!pending.empty()) {
      CordRep* node = pending.back();
      pending.pop_back();
      CheckNode(node);
      if (ABSL_PREDICT_FALSE(node->tag != CONCAT)) {
        AddNode(node);
        continue;
      }

      CordRepConcat* concat_node = node->concat();
      if (concat_node->depth() >= kMinLengthSize ||
          concat_node->length < min_length[concat_node->depth()]) {
        pending.push_back(concat_node->right);
        pending.push_back(concat_node->left);

        if (concat_node->refcount.IsOne()) {
          concat_node->left = concat_freelist_;
          concat_freelist_ = concat_node;
        } else {
          CordRep::Ref(concat_node->right);
          CordRep::Ref(concat_node->left);
          CordRep::Unref(concat_node);
        }
      } else {
        AddNode(node);
      }
    }
  }

  CordRep* ConcatNodes() {
    CordRep* sum = nullptr;
    for (auto* node : trees_) {
      if (node == nullptr) continue;

      sum = PrependNode(node, sum);
      root_length_ -= node->length;
      if (root_length_ == 0) break;
    }
    ABSL_INTERNAL_CHECK(sum != nullptr, "Failed to locate sum node");
    return VerifyTree(sum);
  }

 private:
  CordRep* AppendNode(CordRep* node, CordRep* sum) {
    return (sum == nullptr) ? node : MakeConcat(sum, node);
  }

  CordRep* PrependNode(CordRep* node, CordRep* sum) {
    return (sum == nullptr) ? node : MakeConcat(node, sum);
  }

  void AddNode(CordRep* node) {
    CordRep* sum = nullptr;

    // Collect together everything with which we will merge with node
    int i = 0;
    for (; node->length > min_length[i + 1]; ++i) {
      auto& tree_at_i = trees_[i];

      if (tree_at_i == nullptr) continue;
      sum = PrependNode(tree_at_i, sum);
      tree_at_i = nullptr;
    }

    sum = AppendNode(node, sum);

    // Insert sum into appropriate place in the forest
    for (; sum->length >= min_length[i]; ++i) {
      auto& tree_at_i = trees_[i];
      if (tree_at_i == nullptr) continue;

      sum = MakeConcat(tree_at_i, sum);
      tree_at_i = nullptr;
    }

    // min_length[0] == 1, which means sum->length >= min_length[0]
    assert(i > 0);
    trees_[i - 1] = sum;
  }

  // Make concat node trying to resue existing CordRepConcat nodes we
  // already collected in the concat_freelist_.
  CordRep* MakeConcat(CordRep* left, CordRep* right) {
    if (concat_freelist_ == nullptr) return RawConcat(left, right);

    CordRepConcat* rep = concat_freelist_;
    if (concat_freelist_->left == nullptr) {
      concat_freelist_ = nullptr;
    } else {
      concat_freelist_ = concat_freelist_->left->concat();
    }
    SetConcatChildren(rep, left, right);

    return rep;
  }

  static void CheckNode(CordRep* node) {
    ABSL_INTERNAL_CHECK(node->length != 0u, "");
    if (node->tag == CONCAT) {
      ABSL_INTERNAL_CHECK(node->concat()->left != nullptr, "");
      ABSL_INTERNAL_CHECK(node->concat()->right != nullptr, "");
      ABSL_INTERNAL_CHECK(node->length == (node->concat()->left->length +
                                           node->concat()->right->length),
                          "");
    }
  }

  size_t root_length_;

  // use an inlined vector instead of a flat array to get bounds checking
  absl::InlinedVector<CordRep*, kInlinedVectorSize> trees_;

  // List of concat nodes we can re-use for Cord balancing.
  CordRepConcat* concat_freelist_ = nullptr;
};

static CordRep* Rebalance(CordRep* node) {
  VerifyTree(node);
  assert(node->tag == CONCAT);

  if (node->length == 0) {
    return nullptr;
  }

  CordForest forest(node->length);
  forest.Build(node);
  return forest.ConcatNodes();
}

// --------------------------------------------------------------------
// Comparators

namespace {

int ClampResult(int memcmp_res) {
  return static_cast<int>(memcmp_res > 0) - static_cast<int>(memcmp_res < 0);
}

int CompareChunks(absl::string_view* lhs, absl::string_view* rhs,
                  size_t* size_to_compare) {
  size_t compared_size = std::min(lhs->size(), rhs->size());
  assert(*size_to_compare >= compared_size);
  *size_to_compare -= compared_size;

  int memcmp_res = ::memcmp(lhs->data(), rhs->data(), compared_size);
  if (memcmp_res != 0) return memcmp_res;

  lhs->remove_prefix(compared_size);
  rhs->remove_prefix(compared_size);

  return 0;
}

// This overload set computes comparison results from memcmp result. This
// interface is used inside GenericCompare below. Differet implementations
// are specialized for int and bool. For int we clamp result to {-1, 0, 1}
// set. For bool we just interested in "value == 0".
template <typename ResultType>
ResultType ComputeCompareResult(int memcmp_res) {
  return ClampResult(memcmp_res);
}
template <>
bool ComputeCompareResult<bool>(int memcmp_res) {
  return memcmp_res == 0;
}

}  // namespace

// Helper routine. Locates the first flat chunk of the Cord without
// initializing the iterator.
inline absl::string_view Cord::InlineRep::FindFlatStartPiece() const {
  if (!is_tree()) {
    return absl::string_view(data_.as_chars(), data_.inline_size());
  }

  CordRep* node = tree();
  if (node->tag >= FLAT) {
    return absl::string_view(node->flat()->Data(), node->length);
  }

  if (node->tag == EXTERNAL) {
    return absl::string_view(node->external()->base, node->length);
  }

  if (node->tag == RING) {
    return node->ring()->entry_data(node->ring()->head());
  }

  // Walk down the left branches until we hit a non-CONCAT node.
  while (node->tag == CONCAT) {
    node = node->concat()->left;
  }

  // Get the child node if we encounter a SUBSTRING.
  size_t offset = 0;
  size_t length = node->length;
  assert(length != 0);

  if (node->tag == SUBSTRING) {
    offset = node->substring()->start;
    node = node->substring()->child;
  }

  if (node->tag >= FLAT) {
    return absl::string_view(node->flat()->Data() + offset, length);
  }

  assert((node->tag == EXTERNAL) && "Expect FLAT or EXTERNAL node here");

  return absl::string_view(node->external()->base + offset, length);
}

inline int Cord::CompareSlowPath(absl::string_view rhs, size_t compared_size,
                                 size_t size_to_compare) const {
  auto advance = [](Cord::ChunkIterator* it, absl::string_view* chunk) {
    if (!chunk->empty()) return true;
    ++*it;
    if (it->bytes_remaining_ == 0) return false;
    *chunk = **it;
    return true;
  };

  Cord::ChunkIterator lhs_it = chunk_begin();

  // compared_size is inside first chunk.
  absl::string_view lhs_chunk =
      (lhs_it.bytes_remaining_ != 0) ? *lhs_it : absl::string_view();
  assert(compared_size <= lhs_chunk.size());
  assert(compared_size <= rhs.size());
  lhs_chunk.remove_prefix(compared_size);
  rhs.remove_prefix(compared_size);
  size_to_compare -= compared_size;  // skip already compared size.

  while (advance(&lhs_it, &lhs_chunk) && !rhs.empty()) {
    int comparison_result = CompareChunks(&lhs_chunk, &rhs, &size_to_compare);
    if (comparison_result != 0) return comparison_result;
    if (size_to_compare == 0) return 0;
  }

  return static_cast<int>(rhs.empty()) - static_cast<int>(lhs_chunk.empty());
}

inline int Cord::CompareSlowPath(const Cord& rhs, size_t compared_size,
                                 size_t size_to_compare) const {
  auto advance = [](Cord::ChunkIterator* it, absl::string_view* chunk) {
    if (!chunk->empty()) return true;
    ++*it;
    if (it->bytes_remaining_ == 0) return false;
    *chunk = **it;
    return true;
  };

  Cord::ChunkIterator lhs_it = chunk_begin();
  Cord::ChunkIterator rhs_it = rhs.chunk_begin();

  // compared_size is inside both first chunks.
  absl::string_view lhs_chunk =
      (lhs_it.bytes_remaining_ != 0) ? *lhs_it : absl::string_view();
  absl::string_view rhs_chunk =
      (rhs_it.bytes_remaining_ != 0) ? *rhs_it : absl::string_view();
  assert(compared_size <= lhs_chunk.size());
  assert(compared_size <= rhs_chunk.size());
  lhs_chunk.remove_prefix(compared_size);
  rhs_chunk.remove_prefix(compared_size);
  size_to_compare -= compared_size;  // skip already compared size.

  while (advance(&lhs_it, &lhs_chunk) && advance(&rhs_it, &rhs_chunk)) {
    int memcmp_res = CompareChunks(&lhs_chunk, &rhs_chunk, &size_to_compare);
    if (memcmp_res != 0) return memcmp_res;
    if (size_to_compare == 0) return 0;
  }

  return static_cast<int>(rhs_chunk.empty()) -
         static_cast<int>(lhs_chunk.empty());
}

inline absl::string_view Cord::GetFirstChunk(const Cord& c) {
  return c.contents_.FindFlatStartPiece();
}
inline absl::string_view Cord::GetFirstChunk(absl::string_view sv) {
  return sv;
}

// Compares up to 'size_to_compare' bytes of 'lhs' with 'rhs'. It is assumed
// that 'size_to_compare' is greater that size of smallest of first chunks.
template <typename ResultType, typename RHS>
ResultType GenericCompare(const Cord& lhs, const RHS& rhs,
                          size_t size_to_compare) {
  absl::string_view lhs_chunk = Cord::GetFirstChunk(lhs);
  absl::string_view rhs_chunk = Cord::GetFirstChunk(rhs);

  size_t compared_size = std::min(lhs_chunk.size(), rhs_chunk.size());
  assert(size_to_compare >= compared_size);
  int memcmp_res = ::memcmp(lhs_chunk.data(), rhs_chunk.data(), compared_size);
  if (compared_size == size_to_compare || memcmp_res != 0) {
    return ComputeCompareResult<ResultType>(memcmp_res);
  }

  return ComputeCompareResult<ResultType>(
      lhs.CompareSlowPath(rhs, compared_size, size_to_compare));
}

bool Cord::EqualsImpl(absl::string_view rhs, size_t size_to_compare) const {
  return GenericCompare<bool>(*this, rhs, size_to_compare);
}

bool Cord::EqualsImpl(const Cord& rhs, size_t size_to_compare) const {
  return GenericCompare<bool>(*this, rhs, size_to_compare);
}

template <typename RHS>
inline int SharedCompareImpl(const Cord& lhs, const RHS& rhs) {
  size_t lhs_size = lhs.size();
  size_t rhs_size = rhs.size();
  if (lhs_size == rhs_size) {
    return GenericCompare<int>(lhs, rhs, lhs_size);
  }
  if (lhs_size < rhs_size) {
    auto data_comp_res = GenericCompare<int>(lhs, rhs, lhs_size);
    return data_comp_res == 0 ? -1 : data_comp_res;
  }

  auto data_comp_res = GenericCompare<int>(lhs, rhs, rhs_size);
  return data_comp_res == 0 ? +1 : data_comp_res;
}

int Cord::Compare(absl::string_view rhs) const {
  return SharedCompareImpl(*this, rhs);
}

int Cord::CompareImpl(const Cord& rhs) const {
  return SharedCompareImpl(*this, rhs);
}

bool Cord::EndsWith(absl::string_view rhs) const {
  size_t my_size = size();
  size_t rhs_size = rhs.size();

  if (my_size < rhs_size) return false;

  Cord tmp(*this);
  tmp.RemovePrefix(my_size - rhs_size);
  return tmp.EqualsImpl(rhs, rhs_size);
}

bool Cord::EndsWith(const Cord& rhs) const {
  size_t my_size = size();
  size_t rhs_size = rhs.size();

  if (my_size < rhs_size) return false;

  Cord tmp(*this);
  tmp.RemovePrefix(my_size - rhs_size);
  return tmp.EqualsImpl(rhs, rhs_size);
}

// --------------------------------------------------------------------
// Misc.

Cord::operator std::string() const {
  std::string s;
  absl::CopyCordToString(*this, &s);
  return s;
}

void CopyCordToString(const Cord& src, std::string* dst) {
  if (!src.contents_.is_tree()) {
    src.contents_.CopyTo(dst);
  } else {
    absl::strings_internal::STLStringResizeUninitialized(dst, src.size());
    src.CopyToArraySlowPath(&(*dst)[0]);
  }
}

void Cord::CopyToArraySlowPath(char* dst) const {
  assert(contents_.is_tree());
  absl::string_view fragment;
  if (GetFlatAux(contents_.tree(), &fragment)) {
    memcpy(dst, fragment.data(), fragment.size());
    return;
  }
  for (absl::string_view chunk : Chunks()) {
    memcpy(dst, chunk.data(), chunk.size());
    dst += chunk.size();
  }
}

Cord::ChunkIterator& Cord::ChunkIterator::AdvanceStack() {
  auto& stack_of_right_children = stack_of_right_children_;
  if (stack_of_right_children.empty()) {
    assert(!current_chunk_.empty());  // Called on invalid iterator.
    // We have reached the end of the Cord.
    return *this;
  }

  // Process the next node on the stack.
  CordRep* node = stack_of_right_children.back();
  stack_of_right_children.pop_back();

  // Walk down the left branches until we hit a non-CONCAT node. Save the
  // right children to the stack for subsequent traversal.
  while (node->tag == CONCAT) {
    stack_of_right_children.push_back(node->concat()->right);
    node = node->concat()->left;
  }

  // Get the child node if we encounter a SUBSTRING.
  size_t offset = 0;
  size_t length = node->length;
  if (node->tag == SUBSTRING) {
    offset = node->substring()->start;
    node = node->substring()->child;
  }

  assert(node->tag == EXTERNAL || node->tag >= FLAT);
  assert(length != 0);
  const char* data =
      node->tag == EXTERNAL ? node->external()->base : node->flat()->Data();
  current_chunk_ = absl::string_view(data + offset, length);
  current_leaf_ = node;
  return *this;
}

Cord Cord::ChunkIterator::AdvanceAndReadBytes(size_t n) {
  ABSL_HARDENING_ASSERT(bytes_remaining_ >= n &&
                        "Attempted to iterate past `end()`");
  Cord subcord;

  if (n <= InlineRep::kMaxInline) {
    // Range to read fits in inline data. Flatten it.
    char* data = subcord.contents_.set_data(n);
    while (n > current_chunk_.size()) {
      memcpy(data, current_chunk_.data(), current_chunk_.size());
      data += current_chunk_.size();
      n -= current_chunk_.size();
      ++*this;
    }
    memcpy(data, current_chunk_.data(), n);
    if (n < current_chunk_.size()) {
      RemoveChunkPrefix(n);
    } else if (n > 0) {
      ++*this;
    }
    return subcord;
  }

  if (ring_reader_) {
    size_t chunk_size = current_chunk_.size();
    if (n <= chunk_size && n <= kMaxBytesToCopy) {
      subcord = Cord(current_chunk_.substr(0, n));
    } else {
      auto* ring = CordRep::Ref(ring_reader_.ring())->ring();
      size_t offset = ring_reader_.length() - bytes_remaining_;
      subcord.contents_.set_tree(CordRepRing::SubRing(ring, offset, n));
    }
    if (n < chunk_size) {
      bytes_remaining_ -= n;
      current_chunk_.remove_prefix(n);
    } else {
      AdvanceBytesRing(n);
    }
    return subcord;
  }

  auto& stack_of_right_children = stack_of_right_children_;
  if (n < current_chunk_.size()) {
    // Range to read is a proper subrange of the current chunk.
    assert(current_leaf_ != nullptr);
    CordRep* subnode = CordRep::Ref(current_leaf_);
    const char* data = subnode->tag == EXTERNAL ? subnode->external()->base
                                                : subnode->flat()->Data();
    subnode = NewSubstring(subnode, current_chunk_.data() - data, n);
    subcord.contents_.set_tree(VerifyTree(subnode));
    RemoveChunkPrefix(n);
    return subcord;
  }

  // Range to read begins with a proper subrange of the current chunk.
  assert(!current_chunk_.empty());
  assert(current_leaf_ != nullptr);
  CordRep* subnode = CordRep::Ref(current_leaf_);
  if (current_chunk_.size() < subnode->length) {
    const char* data = subnode->tag == EXTERNAL ? subnode->external()->base
                                                : subnode->flat()->Data();
    subnode = NewSubstring(subnode, current_chunk_.data() - data,
                           current_chunk_.size());
  }
  n -= current_chunk_.size();
  bytes_remaining_ -= current_chunk_.size();

  // Process the next node(s) on the stack, reading whole subtrees depending on
  // their length and how many bytes we are advancing.
  CordRep* node = nullptr;
  while (!stack_of_right_children.empty()) {
    node = stack_of_right_children.back();
    stack_of_right_children.pop_back();
    if (node->length > n) break;
    // TODO(qrczak): This might unnecessarily recreate existing concat nodes.
    // Avoiding that would need pretty complicated logic (instead of
    // current_leaf, keep current_subtree_ which points to the highest node
    // such that the current leaf can be found on the path of left children
    // starting from current_subtree_; delay creating subnode while node is
    // below current_subtree_; find the proper node along the path of left
    // children starting from current_subtree_ if this loop exits while staying
    // below current_subtree_; etc.; alternatively, push parents instead of
    // right children on the stack).
    subnode = Concat(subnode, CordRep::Ref(node));
    n -= node->length;
    bytes_remaining_ -= node->length;
    node = nullptr;
  }

  if (node == nullptr) {
    // We have reached the end of the Cord.
    assert(bytes_remaining_ == 0);
    subcord.contents_.set_tree(VerifyTree(subnode));
    return subcord;
  }

  // Walk down the appropriate branches until we hit a non-CONCAT node. Save the
  // right children to the stack for subsequent traversal.
  while (node->tag == CONCAT) {
    if (node->concat()->left->length > n) {
      // Push right, descend left.
      stack_of_right_children.push_back(node->concat()->right);
      node = node->concat()->left;
    } else {
      // Read left, descend right.
      subnode = Concat(subnode, CordRep::Ref(node->concat()->left));
      n -= node->concat()->left->length;
      bytes_remaining_ -= node->concat()->left->length;
      node = node->concat()->right;
    }
  }

  // Get the child node if we encounter a SUBSTRING.
  size_t offset = 0;
  size_t length = node->length;
  if (node->tag == SUBSTRING) {
    offset = node->substring()->start;
    node = node->substring()->child;
  }

  // Range to read ends with a proper (possibly empty) subrange of the current
  // chunk.
  assert(node->tag == EXTERNAL || node->tag >= FLAT);
  assert(length > n);
  if (n > 0) {
    subnode = Concat(subnode, NewSubstring(CordRep::Ref(node), offset, n));
  }
  const char* data =
      node->tag == EXTERNAL ? node->external()->base : node->flat()->Data();
  current_chunk_ = absl::string_view(data + offset + n, length - n);
  current_leaf_ = node;
  bytes_remaining_ -= n;
  subcord.contents_.set_tree(VerifyTree(subnode));
  return subcord;
}

void Cord::ChunkIterator::AdvanceBytesSlowPath(size_t n) {
  assert(bytes_remaining_ >= n && "Attempted to iterate past `end()`");
  assert(n >= current_chunk_.size());  // This should only be called when
                                       // iterating to a new node.

  n -= current_chunk_.size();
  bytes_remaining_ -= current_chunk_.size();

  if (stack_of_right_children_.empty()) {
    // We have reached the end of the Cord.
    assert(bytes_remaining_ == 0);
    return;
  }

  // Process the next node(s) on the stack, skipping whole subtrees depending on
  // their length and how many bytes we are advancing.
  CordRep* node = nullptr;
  auto& stack_of_right_children = stack_of_right_children_;
  while (!stack_of_right_children.empty()) {
    node = stack_of_right_children.back();
    stack_of_right_children.pop_back();
    if (node->length > n) break;
    n -= node->length;
    bytes_remaining_ -= node->length;
    node = nullptr;
  }

  if (node == nullptr) {
    // We have reached the end of the Cord.
    assert(bytes_remaining_ == 0);
    return;
  }

  // Walk down the appropriate branches until we hit a non-CONCAT node. Save the
  // right children to the stack for subsequent traversal.
  while (node->tag == CONCAT) {
    if (node->concat()->left->length > n) {
      // Push right, descend left.
      stack_of_right_children.push_back(node->concat()->right);
      node = node->concat()->left;
    } else {
      // Skip left, descend right.
      n -= node->concat()->left->length;
      bytes_remaining_ -= node->concat()->left->length;
      node = node->concat()->right;
    }
  }

  // Get the child node if we encounter a SUBSTRING.
  size_t offset = 0;
  size_t length = node->length;
  if (node->tag == SUBSTRING) {
    offset = node->substring()->start;
    node = node->substring()->child;
  }

  assert(node->tag == EXTERNAL || node->tag >= FLAT);
  assert(length > n);
  const char* data =
      node->tag == EXTERNAL ? node->external()->base : node->flat()->Data();
  current_chunk_ = absl::string_view(data + offset + n, length - n);
  current_leaf_ = node;
  bytes_remaining_ -= n;
}

char Cord::operator[](size_t i) const {
  ABSL_HARDENING_ASSERT(i < size());
  size_t offset = i;
  const CordRep* rep = contents_.tree();
  if (rep == nullptr) {
    return contents_.data()[i];
  }
  while (true) {
    assert(rep != nullptr);
    assert(offset < rep->length);
    if (rep->tag >= FLAT) {
      // Get the "i"th character directly from the flat array.
      return rep->flat()->Data()[offset];
    } else if (rep->tag == RING) {
      return rep->ring()->GetCharacter(offset);
    } else if (rep->tag == EXTERNAL) {
      // Get the "i"th character from the external array.
      return rep->external()->base[offset];
    } else if (rep->tag == CONCAT) {
      // Recursively branch to the side of the concatenation that the "i"th
      // character is on.
      size_t left_length = rep->concat()->left->length;
      if (offset < left_length) {
        rep = rep->concat()->left;
      } else {
        offset -= left_length;
        rep = rep->concat()->right;
      }
    } else {
      // This must be a substring a node, so bypass it to get to the child.
      assert(rep->tag == SUBSTRING);
      offset += rep->substring()->start;
      rep = rep->substring()->child;
    }
  }
}

absl::string_view Cord::FlattenSlowPath() {
  size_t total_size = size();
  CordRep* new_rep;
  char* new_buffer;

  // Try to put the contents into a new flat rep. If they won't fit in the
  // biggest possible flat node, use an external rep instead.
  if (total_size <= kMaxFlatLength) {
    new_rep = CordRepFlat::New(total_size);
    new_rep->length = total_size;
    new_buffer = new_rep->flat()->Data();
    CopyToArraySlowPath(new_buffer);
  } else {
    new_buffer = std::allocator<char>().allocate(total_size);
    CopyToArraySlowPath(new_buffer);
    new_rep = absl::cord_internal::NewExternalRep(
        absl::string_view(new_buffer, total_size), [](absl::string_view s) {
          std::allocator<char>().deallocate(const_cast<char*>(s.data()),
                                            s.size());
        });
  }
  if (CordRep* tree = contents_.tree()) {
    CordRep::Unref(tree);
  }
  contents_.set_tree(new_rep);
  return absl::string_view(new_buffer, total_size);
}

/* static */ bool Cord::GetFlatAux(CordRep* rep, absl::string_view* fragment) {
  assert(rep != nullptr);
  if (rep->tag >= FLAT) {
    *fragment = absl::string_view(rep->flat()->Data(), rep->length);
    return true;
  } else if (rep->tag == EXTERNAL) {
    *fragment = absl::string_view(rep->external()->base, rep->length);
    return true;
  } else if (rep->tag == SUBSTRING) {
    CordRep* child = rep->substring()->child;
    if (child->tag >= FLAT) {
      *fragment = absl::string_view(
          child->flat()->Data() + rep->substring()->start, rep->length);
      return true;
    } else if (child->tag == EXTERNAL) {
      *fragment = absl::string_view(
          child->external()->base + rep->substring()->start, rep->length);
      return true;
    }
  }
  return false;
}

/* static */ void Cord::ForEachChunkAux(
    absl::cord_internal::CordRep* rep,
    absl::FunctionRef<void(absl::string_view)> callback) {
  if (rep->tag == RING) {
    ChunkIterator it(rep), end;
    while (it != end) {
      callback(*it);
      ++it;
    }
    return;
  }

  assert(rep != nullptr);
  int stack_pos = 0;
  constexpr int stack_max = 128;
  // Stack of right branches for tree traversal
  absl::cord_internal::CordRep* stack[stack_max];
  absl::cord_internal::CordRep* current_node = rep;
  while (true) {
    if (current_node->tag == CONCAT) {
      if (stack_pos == stack_max) {
        // There's no more room on our stack array to add another right branch,
        // and the idea is to avoid allocations, so call this function
        // recursively to navigate this subtree further.  (This is not something
        // we expect to happen in practice).
        ForEachChunkAux(current_node, callback);

        // Pop the next right branch and iterate.
        current_node = stack[--stack_pos];
        continue;
      } else {
        // Save the right branch for later traversal and continue down the left
        // branch.
        stack[stack_pos++] = current_node->concat()->right;
        current_node = current_node->concat()->left;
        continue;
      }
    }
    // This is a leaf node, so invoke our callback.
    absl::string_view chunk;
    bool success = GetFlatAux(current_node, &chunk);
    assert(success);
    if (success) {
      callback(chunk);
    }
    if (stack_pos == 0) {
      // end of traversal
      return;
    }
    current_node = stack[--stack_pos];
  }
}

static void DumpNode(CordRep* rep, bool include_data, std::ostream* os,
                     int indent) {
  const int kIndentStep = 1;
  absl::InlinedVector<CordRep*, kInlinedVectorSize> stack;
  absl::InlinedVector<int, kInlinedVectorSize> indents;
  for (;;) {
    *os << std::setw(3) << rep->refcount.Get();
    *os << " " << std::setw(7) << rep->length;
    *os << " [";
    if (include_data) *os << static_cast<void*>(rep);
    *os << "]";
    *os << " " << (IsRootBalanced(rep) ? 'b' : 'u');
    *os << " " << std::setw(indent) << "";
    if (rep->tag == CONCAT) {
      *os << "CONCAT depth=" << Depth(rep) << "\n";
      indent += kIndentStep;
      indents.push_back(indent);
      stack.push_back(rep->concat()->right);
      rep = rep->concat()->left;
    } else if (rep->tag == SUBSTRING) {
      *os << "SUBSTRING @ " << rep->substring()->start << "\n";
      indent += kIndentStep;
      rep = rep->substring()->child;
    } else {  // Leaf or ring
      if (rep->tag == EXTERNAL) {
        *os << "EXTERNAL [";
        if (include_data)
          *os << absl::CEscape(std::string(rep->external()->base, rep->length));
        *os << "]\n";
      } else if (rep->tag >= FLAT) {
        *os << "FLAT cap=" << rep->flat()->Capacity()
            << " [";
        if (include_data)
          *os << absl::CEscape(std::string(rep->flat()->Data(), rep->length));
        *os << "]\n";
      } else {
        assert(rep->tag == RING);
        auto* ring = rep->ring();
        *os << "RING, entries = " << ring->entries() << "\n";
        CordRepRing::index_type head = ring->head();
        do {
          DumpNode(ring->entry_child(head), include_data, os,
                   indent + kIndentStep);
          head = ring->advance(head);;
        } while (head != ring->tail());
      }
      if (stack.empty()) break;
      rep = stack.back();
      stack.pop_back();
      indent = indents.back();
      indents.pop_back();
    }
  }
  ABSL_INTERNAL_CHECK(indents.empty(), "");
}

static std::string ReportError(CordRep* root, CordRep* node) {
  std::ostringstream buf;
  buf << "Error at node " << node << " in:";
  DumpNode(root, true, &buf);
  return buf.str();
}

static bool VerifyNode(CordRep* root, CordRep* start_node,
                       bool full_validation) {
  absl::InlinedVector<CordRep*, 2> worklist;
  worklist.push_back(start_node);
  do {
    CordRep* node = worklist.back();
    worklist.pop_back();

    ABSL_INTERNAL_CHECK(node != nullptr, ReportError(root, node));
    if (node != root) {
      ABSL_INTERNAL_CHECK(node->length != 0, ReportError(root, node));
    }

    if (node->tag == CONCAT) {
      ABSL_INTERNAL_CHECK(node->concat()->left != nullptr,
                          ReportError(root, node));
      ABSL_INTERNAL_CHECK(node->concat()->right != nullptr,
                          ReportError(root, node));
      ABSL_INTERNAL_CHECK((node->length == node->concat()->left->length +
                                               node->concat()->right->length),
                          ReportError(root, node));
      if (full_validation) {
        worklist.push_back(node->concat()->right);
        worklist.push_back(node->concat()->left);
      }
    } else if (node->tag >= FLAT) {
      ABSL_INTERNAL_CHECK(
          node->length <= node->flat()->Capacity(),
          ReportError(root, node));
    } else if (node->tag == EXTERNAL) {
      ABSL_INTERNAL_CHECK(node->external()->base != nullptr,
                          ReportError(root, node));
    } else if (node->tag == SUBSTRING) {
      ABSL_INTERNAL_CHECK(
          node->substring()->start < node->substring()->child->length,
          ReportError(root, node));
      ABSL_INTERNAL_CHECK(node->substring()->start + node->length <=
                              node->substring()->child->length,
                          ReportError(root, node));
    }
  } while (!worklist.empty());
  return true;
}

// Traverses the tree and computes the total memory allocated.
/* static */ size_t Cord::MemoryUsageAux(const CordRep* rep) {
  size_t total_mem_usage = 0;

  // Allow a quick exit for the common case that the root is a leaf.
  if (RepMemoryUsageLeaf(rep, &total_mem_usage)) {
    return total_mem_usage;
  }

  // Iterate over the tree. cur_node is never a leaf node and leaf nodes will
  // never be appended to tree_stack. This reduces overhead from manipulating
  // tree_stack.
  absl::InlinedVector<const CordRep*, kInlinedVectorSize> tree_stack;
  const CordRep* cur_node = rep;
  while (true) {
    const CordRep* next_node = nullptr;

    if (cur_node->tag == CONCAT) {
      total_mem_usage += sizeof(CordRepConcat);
      const CordRep* left = cur_node->concat()->left;
      if (!RepMemoryUsageLeaf(left, &total_mem_usage)) {
        next_node = left;
      }

      const CordRep* right = cur_node->concat()->right;
      if (!RepMemoryUsageLeaf(right, &total_mem_usage)) {
        if (next_node) {
          tree_stack.push_back(next_node);
        }
        next_node = right;
      }
    } else if (cur_node->tag == RING) {
      total_mem_usage += CordRepRing::AllocSize(cur_node->ring()->capacity());
      const CordRepRing* ring = cur_node->ring();
      CordRepRing::index_type pos = ring->head(), tail = ring->tail();
      do {
        CordRep* node = ring->entry_child(pos);
        assert(node->tag >= FLAT || node->tag == EXTERNAL);
        RepMemoryUsageLeaf(node, &total_mem_usage);
      } while ((pos = ring->advance(pos)) != tail);
    } else {
      // Since cur_node is not a leaf or a concat node it must be a substring.
      assert(cur_node->tag == SUBSTRING);
      total_mem_usage += sizeof(CordRepSubstring);
      next_node = cur_node->substring()->child;
      if (RepMemoryUsageLeaf(next_node, &total_mem_usage)) {
        next_node = nullptr;
      }
    }

    if (!next_node) {
      if (tree_stack.empty()) {
        return total_mem_usage;
      }
      next_node = tree_stack.back();
      tree_stack.pop_back();
    }
    cur_node = next_node;
  }
}

std::ostream& operator<<(std::ostream& out, const Cord& cord) {
  for (absl::string_view chunk : cord.Chunks()) {
    out.write(chunk.data(), chunk.size());
  }
  return out;
}

namespace strings_internal {
size_t CordTestAccess::FlatOverhead() { return cord_internal::kFlatOverhead; }
size_t CordTestAccess::MaxFlatLength() { return cord_internal::kMaxFlatLength; }
size_t CordTestAccess::FlatTagToLength(uint8_t tag) {
  return cord_internal::TagToLength(tag);
}
uint8_t CordTestAccess::LengthToTag(size_t s) {
  ABSL_INTERNAL_CHECK(s <= kMaxFlatLength, absl::StrCat("Invalid length ", s));
  return cord_internal::AllocatedSizeToTag(s + cord_internal::kFlatOverhead);
}
size_t CordTestAccess::SizeofCordRepConcat() { return sizeof(CordRepConcat); }
size_t CordTestAccess::SizeofCordRepExternal() {
  return sizeof(CordRepExternal);
}
size_t CordTestAccess::SizeofCordRepSubstring() {
  return sizeof(CordRepSubstring);
}
}  // namespace strings_internal
ABSL_NAMESPACE_END
}  // namespace absl
