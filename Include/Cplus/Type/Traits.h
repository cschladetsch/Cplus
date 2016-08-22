#pragma once

#include "Cplus/Builtin/Memory/Config.h"
#include "TypeNumber.h"

typedef k_Value (*k_Traits_Unary_Function)(k_Value *);
typedef k_Value (*k_Traits_Binary_Function)(k_Value *, k_Value *);

typedef k_StringStream *(*k_Traits_StringStream_Function)(k_Value *, k_StringStream *);
typedef k_BinaryStream *(*k_Traits_BinaryStream_Function)(k_Value *, k_BinaryStream *);

typedef struct k_Traits_t
{
	k_Traits_Unary_Function construct;
	k_Traits_Unary_Function destroy;

	k_Traits_Unary_Function toString;

	k_Traits_Binary_Function assign;

	k_Traits_Binary_Function equiv;
	k_Traits_Binary_Function less;
	k_Traits_Binary_Function greater;

	k_Traits_Binary_Function plus;
	k_Traits_Binary_Function minus;
	k_Traits_Binary_Function multiply;
	k_Traits_Binary_Function divide;

	k_Traits_StringStream_Function stringStreamInsert;
	k_Traits_StringStream_Function stringStreamExtract;

	k_Traits_BinaryStream_Function binaryStreamInsert;
	k_Traits_BinaryStream_Function binaryStreamExtract;
} k_Traits;



