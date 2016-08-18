#pragma once

#include "KAI/Base.h"

typedef struct k_String_t
{
	k_Base base;
	char *s;
	int length;
} k_String;

extern k_Allocator k_String_Alloc;

k_String *k_String_Concat(k_String *, k_String *);
