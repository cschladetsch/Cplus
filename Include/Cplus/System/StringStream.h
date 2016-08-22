#pragma once

#include "String.h"

typedef struct k_StringStream_t
{
	k_Base base;
	k_String string;
	int cursor;
} k_StringStream;
extern k_Allocator k_StringStream_Alloc;

void k_StringStream_Insert(k_StringStream *, k_Object *);
k_Object *k_StringStream_Extract(k_StringStream *);
k_String *k_StringStream_ToString(k_StringStream *);
