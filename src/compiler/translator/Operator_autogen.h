// GENERATED FILE - DO NOT EDIT.
// Generated by gen_builtin_symbols.py using data from builtin_function_declarations.txt.
//
// Copyright 2021 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Operator_autogen.h:
//   Operators used by the high-level (parse tree) representation.

#ifndef COMPILER_TRANSLATOR_OPERATOR_AUTOGEN_H_
#define COMPILER_TRANSLATOR_OPERATOR_AUTOGEN_H_

#include <stdint.h>

namespace sh
{

enum TOperator : uint16_t
{
    EOpNull,  // if in a node, should only mean a node is still being built

    // Call a function defined in the AST. This might be a user-defined function or a function
    // inserted by an AST transformation.
    EOpCallFunctionInAST,

    // Call an internal helper function with a raw implementation - the implementation can't be
    // subject to AST transformations. Raw functions have a few constraints to keep them compatible
    // with AST traversers:
    // * They should not return arrays.
    // * They should not have out parameters.
    //
    // DEPRECATED; DO NOT USE.  TODO: remove this.  http://anglebug.com/42264589
    //
    EOpCallInternalRawFunction,

    //
    // Branch (TIntermBranch)
    //

    EOpKill,  // Fragment only
    EOpReturn,
    EOpBreak,
    EOpContinue,

    //
    // Constructor (TIntermAggregate)
    //

    EOpConstruct,

    //
    // Unary operators with special GLSL syntax (TIntermUnary).
    //

    EOpNegative,
    EOpPositive,
    EOpLogicalNot,
    EOpBitwiseNot,

    EOpPostIncrement,
    EOpPostDecrement,
    EOpPreIncrement,
    EOpPreDecrement,

    EOpArrayLength,

    //
    // Binary operators with special GLSL syntax (TIntermBinary).
    //

    EOpAdd,
    EOpSub,
    EOpMul,
    EOpDiv,
    EOpIMod,

    EOpEqual,
    EOpNotEqual,
    EOpLessThan,
    EOpGreaterThan,
    EOpLessThanEqual,
    EOpGreaterThanEqual,

    EOpComma,

    EOpVectorTimesScalar,
    EOpVectorTimesMatrix,
    EOpMatrixTimesVector,
    EOpMatrixTimesScalar,
    EOpMatrixTimesMatrix,

    EOpLogicalOr,
    EOpLogicalXor,
    EOpLogicalAnd,

    EOpBitShiftLeft,
    EOpBitShiftRight,

    EOpBitwiseAnd,
    EOpBitwiseXor,
    EOpBitwiseOr,

    EOpIndexDirect,
    EOpIndexIndirect,
    EOpIndexDirectStruct,
    EOpIndexDirectInterfaceBlock,

    //
    // Moves (TIntermBinary)
    //

    EOpAssign,
    EOpInitialize,
    EOpAddAssign,
    EOpSubAssign,

    EOpMulAssign,
    EOpVectorTimesMatrixAssign,
    EOpVectorTimesScalarAssign,
    EOpMatrixTimesScalarAssign,
    EOpMatrixTimesMatrixAssign,

    EOpDivAssign,
    EOpIModAssign,
    EOpBitShiftLeftAssign,
    EOpBitShiftRightAssign,
    EOpBitwiseAndAssign,
    EOpBitwiseXorAssign,
    EOpBitwiseOrAssign,

    // Not an op, but a marker for the start of built-in ops.
    EOpLastNonBuiltIn = EOpBitwiseOrAssign,

    //
    // Built-in functions mapped to operators (either unary (TIntermUnary) or with multiple
    // parameters (TIntermAggregate))
    //

    // Group Math

    // Group MathTrigonometric
    EOpRadians,  // Unary
    EOpDegrees,  // Unary
    EOpSin,      // Unary
    EOpCos,      // Unary
    EOpTan,      // Unary
    EOpAsin,     // Unary
    EOpAcos,     // Unary
    EOpAtan,
    EOpSinh,   // Unary
    EOpCosh,   // Unary
    EOpTanh,   // Unary
    EOpAsinh,  // Unary
    EOpAcosh,  // Unary
    EOpAtanh,  // Unary

    // Group MathExponential
    EOpPow,
    EOpExp,          // Unary
    EOpLog,          // Unary
    EOpExp2,         // Unary
    EOpLog2,         // Unary
    EOpSqrt,         // Unary
    EOpInversesqrt,  // Unary

    // Group MathCommon
    EOpAbs,        // Unary
    EOpSign,       // Unary
    EOpFloor,      // Unary
    EOpTrunc,      // Unary
    EOpRound,      // Unary
    EOpRoundEven,  // Unary
    EOpCeil,       // Unary
    EOpFract,      // Unary
    EOpMod,
    EOpMin,
    EOpMax,
    EOpClamp,
    EOpMix,
    EOpStep,
    EOpSmoothstep,
    EOpModf,
    EOpIsnan,            // Unary
    EOpIsinf,            // Unary
    EOpFloatBitsToInt,   // Unary
    EOpFloatBitsToUint,  // Unary
    EOpIntBitsToFloat,   // Unary
    EOpUintBitsToFloat,  // Unary
    EOpFma,
    EOpFrexp,
    EOpLdexp,
    EOpPackSnorm2x16,    // Unary
    EOpPackHalf2x16,     // Unary
    EOpUnpackSnorm2x16,  // Unary
    EOpUnpackHalf2x16,   // Unary
    EOpPackUnorm2x16,    // Unary
    EOpUnpackUnorm2x16,  // Unary
    EOpPackUnorm4x8,     // Unary
    EOpPackSnorm4x8,     // Unary
    EOpUnpackUnorm4x8,   // Unary
    EOpUnpackSnorm4x8,   // Unary

    // Group MathGeometric
    EOpLength,  // Unary
    EOpDistance,
    EOpDot,
    EOpCross,
    EOpNormalize,  // Unary
    EOpFaceforward,
    EOpReflect,
    EOpRefract,

    // Group MathMatrix
    EOpMatrixCompMult,
    EOpOuterProduct,
    EOpTranspose,    // Unary
    EOpDeterminant,  // Unary
    EOpInverse,      // Unary

    // Group MathVector
    EOpLessThanComponentWise,
    EOpLessThanEqualComponentWise,
    EOpGreaterThanComponentWise,
    EOpGreaterThanEqualComponentWise,
    EOpEqualComponentWise,
    EOpNotEqualComponentWise,
    EOpAny,               // Unary
    EOpAll,               // Unary
    EOpNotComponentWise,  // Unary

    // Group MathInteger
    EOpBitfieldExtract,
    EOpBitfieldInsert,
    EOpBitfieldReverse,  // Unary
    EOpBitCount,         // Unary
    EOpFindLSB,          // Unary
    EOpFindMSB,          // Unary
    EOpUaddCarry,
    EOpUsubBorrow,
    EOpUmulExtended,
    EOpImulExtended,

    // Group Texture

    // Group TextureFirstVersions
    EOpTexture2D,
    EOpTexture2DProj,
    EOpTextureCube,
    EOpTexture3D,
    EOpTexture3DProj,
    EOpShadow2DEXT,
    EOpShadow2DProjEXT,
    EOpTexture2DRect,
    EOpTexture2DRectProj,
    EOpTexture2DGradEXT,
    EOpTexture2DProjGradEXT,
    EOpTextureCubeGradEXT,
    EOpTextureVideoWEBGL,

    // Group TextureFirstVersionsBias
    EOpTexture2DBias,
    EOpTexture2DProjBias,
    EOpTextureCubeBias,
    EOpTexture3DBias,
    EOpTexture3DProjBias,

    // Group TextureFirstVersionsLod
    EOpTexture3DLod,
    EOpTexture3DProjLod,

    // Group TextureFirstVersionsLodVS
    EOpTexture2DLodVS,
    EOpTexture2DProjLodVS,
    EOpTextureCubeLodVS,

    // Group TextureFirstVersionsLodFS
    EOpTexture2DLodEXTFS,
    EOpTexture2DProjLodEXTFS,
    EOpTextureCubeLodEXTFS,

    // Group TextureNoBias
    EOpTexture,
    EOpTextureProj,
    EOpTextureLod,
    EOpTextureSize,
    EOpTextureProjLod,
    EOpTexelFetch,
    EOpTextureGrad,
    EOpTextureProjGrad,

    // Group TextureBias
    EOpTextureBias,
    EOpTextureProjBias,

    // Group TextureOffsetNoBias
    EOpTextureOffset,
    EOpTextureProjOffset,
    EOpTextureLodOffset,
    EOpTextureProjLodOffset,
    EOpTexelFetchOffset,
    EOpTextureGradOffset,
    EOpTextureProjGradOffset,

    // Group TextureOffsetBias
    EOpTextureOffsetBias,
    EOpTextureProjOffsetBias,

    // Group TextureGather

    // Group TextureGatherNoComp
    EOpTextureGather,

    // Group TextureGatherComp
    EOpTextureGatherComp,

    // Group TextureGatherRef
    EOpTextureGatherRef,

    // Group TextureGatherOffset

    // Group TextureGatherOffsetNoComp
    EOpTextureGatherOffset,

    // Group TextureGatherOffsetComp
    EOpTextureGatherOffsetComp,

    // Group TextureGatherOffsetRef
    EOpTextureGatherOffsetRef,

    // Group TextureGatherOffsets

    // Group TextureGatherOffsetsNoComp
    EOpTextureGatherOffsets,

    // Group TextureGatherOffsetsComp
    EOpTextureGatherOffsetsComp,

    // Group TextureGatherOffsetsRef
    EOpTextureGatherOffsetsRef,

    // Group TextureQueryLod
    EOpTextureQueryLOD,

    // Group EXT_YUV_target
    EOpRgb_2_yuv,
    EOpYuv_2_rgb,

    // Group DerivativesFS
    EOpDFdx,
    EOpDFdy,
    EOpFwidth,

    // Group InterpolationFS
    EOpInterpolateAtCentroid,
    EOpInterpolateAtSample,
    EOpInterpolateAtOffset,

    // Group AtomicCounter
    EOpAtomicCounter,
    EOpAtomicCounterIncrement,
    EOpAtomicCounterDecrement,

    // Group AtomicMemory
    EOpAtomicAdd,
    EOpAtomicMin,
    EOpAtomicMax,
    EOpAtomicAnd,
    EOpAtomicOr,
    EOpAtomicXor,
    EOpAtomicExchange,
    EOpAtomicCompSwap,

    // Group Image
    EOpImageSize,

    // Group ImageStore
    EOpImageStore,

    // Group ImageLoad
    EOpImageLoad,

    // Group ImageAtomic
    EOpImageAtomicAdd,
    EOpImageAtomicMin,
    EOpImageAtomicMax,
    EOpImageAtomicAnd,
    EOpImageAtomicOr,
    EOpImageAtomicXor,
    EOpImageAtomicExchange,
    EOpImageAtomicCompSwap,

    // Group PixelLocal

    // Group PixelLocalLoad
    EOpPixelLocalLoadANGLE,

    // Group PixelLocalStore
    EOpPixelLocalStoreANGLE,

    // Group FragmentSynchronization
    EOpBeginInvocationInterlockNV,
    EOpEndInvocationInterlockNV,
    EOpBeginFragmentShaderOrderingINTEL,
    EOpBeginInvocationInterlockARB,
    EOpEndInvocationInterlockARB,

    // Group Barrier
    EOpMemoryBarrier,
    EOpMemoryBarrierAtomicCounter,
    EOpMemoryBarrierBuffer,
    EOpMemoryBarrierImage,

    // Group ESSL310CS
    EOpBarrier,
    EOpMemoryBarrierShared,
    EOpGroupMemoryBarrier,

    // Group ESSL310TCS
    EOpBarrierTCS,

    // Group GS
    EOpEmitVertex,
    EOpEndPrimitive,

    // Group SubpassInput
    EOpSubpassLoad,

    // Group MetalFragmentSample
    EOpNumSamples,
    EOpSamplePosition,
    EOpInterpolateAtCenter,

    // Group MetalCommon
    EOpSaturate,
};

// Returns the string corresponding to the operator in GLSL.  For built-in functions use the
// function name directly.
const char *GetOperatorString(TOperator op);

// Say whether or not a binary or unary operation changes the value of a variable.
bool IsAssignment(TOperator op);

namespace BuiltInGroup
{
static inline bool IsBuiltIn(TOperator op)
{
    return op > EOpLastNonBuiltIn;
}
static inline bool IsMath(TOperator op)
{
    return op >= EOpRadians && op <= EOpImulExtended;
}
static inline bool IsTextureOffsetNoBias(TOperator op)
{
    return op >= EOpTextureOffset && op <= EOpTextureProjGradOffset;
}
static inline bool IsTextureOffsetBias(TOperator op)
{
    return op >= EOpTextureOffsetBias && op <= EOpTextureProjOffsetBias;
}
static inline bool IsTextureGatherNoComp(TOperator op)
{
    return op >= EOpTextureGather && op <= EOpTextureGather;
}
static inline bool IsTextureGatherComp(TOperator op)
{
    return op >= EOpTextureGatherComp && op <= EOpTextureGatherComp;
}
static inline bool IsTextureGatherRef(TOperator op)
{
    return op >= EOpTextureGatherRef && op <= EOpTextureGatherRef;
}
static inline bool IsTextureGatherOffsetNoComp(TOperator op)
{
    return op >= EOpTextureGatherOffset && op <= EOpTextureGatherOffset;
}
static inline bool IsTextureGatherOffsetComp(TOperator op)
{
    return op >= EOpTextureGatherOffsetComp && op <= EOpTextureGatherOffsetComp;
}
static inline bool IsTextureGatherOffsetRef(TOperator op)
{
    return op >= EOpTextureGatherOffsetRef && op <= EOpTextureGatherOffsetRef;
}
static inline bool IsTextureGatherOffset(TOperator op)
{
    return op >= EOpTextureGatherOffset && op <= EOpTextureGatherOffsetRef;
}
static inline bool IsTextureGatherOffsetsNoComp(TOperator op)
{
    return op >= EOpTextureGatherOffsets && op <= EOpTextureGatherOffsets;
}
static inline bool IsTextureGatherOffsetsComp(TOperator op)
{
    return op >= EOpTextureGatherOffsetsComp && op <= EOpTextureGatherOffsetsComp;
}
static inline bool IsTextureGatherOffsetsRef(TOperator op)
{
    return op >= EOpTextureGatherOffsetsRef && op <= EOpTextureGatherOffsetsRef;
}
static inline bool IsTextureGatherOffsets(TOperator op)
{
    return op >= EOpTextureGatherOffsets && op <= EOpTextureGatherOffsetsRef;
}
static inline bool IsTextureGather(TOperator op)
{
    return op >= EOpTextureGather && op <= EOpTextureGatherOffsetsRef;
}
static inline bool IsTexture(TOperator op)
{
    return op >= EOpTexture2D && op <= EOpTextureQueryLOD;
}
static inline bool IsDerivativesFS(TOperator op)
{
    return op >= EOpDFdx && op <= EOpFwidth;
}
static inline bool IsInterpolationFS(TOperator op)
{
    return op >= EOpInterpolateAtCentroid && op <= EOpInterpolateAtOffset;
}
static inline bool IsAtomicCounter(TOperator op)
{
    return op >= EOpAtomicCounter && op <= EOpAtomicCounterDecrement;
}
static inline bool IsAtomicMemory(TOperator op)
{
    return op >= EOpAtomicAdd && op <= EOpAtomicCompSwap;
}
static inline bool IsImageStore(TOperator op)
{
    return op >= EOpImageStore && op <= EOpImageStore;
}
static inline bool IsImageLoad(TOperator op)
{
    return op >= EOpImageLoad && op <= EOpImageLoad;
}
static inline bool IsImageAtomic(TOperator op)
{
    return op >= EOpImageAtomicAdd && op <= EOpImageAtomicCompSwap;
}
static inline bool IsImage(TOperator op)
{
    return op >= EOpImageSize && op <= EOpImageAtomicCompSwap;
}
static inline bool IsPixelLocalLoad(TOperator op)
{
    return op >= EOpPixelLocalLoadANGLE && op <= EOpPixelLocalLoadANGLE;
}
static inline bool IsPixelLocalStore(TOperator op)
{
    return op >= EOpPixelLocalStoreANGLE && op <= EOpPixelLocalStoreANGLE;
}
static inline bool IsPixelLocal(TOperator op)
{
    return op >= EOpPixelLocalLoadANGLE && op <= EOpPixelLocalStoreANGLE;
}
}  // namespace BuiltInGroup

}  // namespace sh

#endif  // COMPILER_TRANSLATOR_OPERATOR_AUTOGEN_H_
