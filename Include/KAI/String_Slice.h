#pragma once

#include "KAI/Base.h"

typedef struct k_String_Slice_t
{
	const char *start;
	const char *end;
} k_String_Slice;

void k_String_Slice_Construct(k_String_Slice *, const char *, const char *);
size_t k_String_Slice_Length(const k_String_Slice *);

