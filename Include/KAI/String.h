#pragma once

#include "KAI/Base.h"

typedef struct k_String_t
{
	k_Base base;
	int length;
	k_Vector str;
} k_String;

extern k_Allocator k_String_Alloc;

k_String *k_String_New();
k_String *k_String_New2(const char *);
k_String *k_String_New3(const k_Allocator *);

k_String k_String_Construct();
k_String k_String_Construct(const char *);
k_String k_String_Construct(const k_Allocator *);

void k_String_Destroy(k_String *);

k_String *k_String_Concat(k_String *, k_String *);
