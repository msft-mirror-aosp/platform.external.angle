//
// Copyright 2024 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#ifndef COMPILER_TRANSLATOR_WGSL_OUTPUT_UNIFORM_BLOCKS_H_
#define COMPILER_TRANSLATOR_WGSL_OUTPUT_UNIFORM_BLOCKS_H_

#include "compiler/translator/Common.h"
#include "compiler/translator/Compiler.h"
#include "compiler/translator/IntermNode.h"

namespace sh
{

const char kDefaultUniformBlockVarType[]           = "ANGLE_DefaultUniformBlock";
const char kDefaultUniformBlockVarName[]           = "ANGLE_defaultUniformBlock";
const uint32_t kDefaultUniformBlockBindGroup       = 0;
const uint32_t kDefaultVertexUniformBlockBinding   = 0;
const uint32_t kDefaultFragmentUniformBlockBinding = 1;

const char kWrappedStructFieldName[] = "elem";

struct UniformBlockMetadata
{
    // A list of structs used anywhere in the uniform address space. These will require special
    // handling (@align() attributes, wrapping of basic types, etc.) to ensure they fit WGSL's
    // uniform layout requirements.
    // The key is TSymbolUniqueId::get().
    TUnorderedSet<int> structsInUniformAddressSpace;
};

// Given a GLSL AST `root`, fills in `outMetadata`, to be used when outputting WGSL.
// If the AST is manipulated after calling this, it may be out of sync with the data recorded in
// `outMetadata`.
bool RecordUniformBlockMetadata(TIntermBlock *root, UniformBlockMetadata &outMetadata);

// Based on the GLSL, some extra WGSL will have to be generated so it can be referenced by
// the WGSL generated by the traverser, This tracks exactly which WGSL snippets will need to be
// generated,
struct WGSLGenerationMetadataForUniforms
{
    // Arrays must have a stride of at least 16 if used in the uniform address spaces. If the array
    // element type doesn't have an aligned size of a multiple of 16 (e.g. f32), the element type
    // must be wrapped in a struct which is then aligned to 16. Adding to
    // `arrayElementTypesInUniforms` will cause `OutputUniformWrapperStructsAndConversions` to
    // generate a WGSL wrapper struct of the form:
    //
    // struct ANGLE_wrapper_f32 {
    //   @align(16) elem : f32;
    // };
    TSet<TType> arrayElementTypesInUniforms;

    // If we need to convert arrays with wrapped element types into arrays with unwrapped element
    // types, the necessary conversions are listed here.
    TSet<TType> arrayElementTypesThatNeedUnwrappingConversions;
};
bool OutputUniformWrapperStructsAndConversions(
    TInfoSinkBase &output,
    const WGSLGenerationMetadataForUniforms &arrayElementTypesInUniforms);

ImmutableString MakeUnwrappingArrayConversionFunctionName(const TType *type);

// TODO(anglebug.com/42267100): for now does not output all uniform blocks,
// just the default block. (fails for  matCx2, bool.)
bool OutputUniformBlocks(TCompiler *compiler, TIntermBlock *root);

}  // namespace sh

#endif  // COMPILER_TRANSLATOR_WGSL_OUTPUT_UNIFORM_BLOCKS_H_
