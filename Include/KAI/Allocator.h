#pragma once

#include "ForwardDeclarations.h"

typedef k_Any (*k_New_Function)(k_Any args);
typedef void (*k_Construct_Function)(k_Any where, k_Any args);
typedef void (*k_Destroy_Function)(k_Any);

typedef struct k_Allocator_t
{
	k_New_Function new;
	k_Construct_Function construct;
	k_Destroy_Function destroy;
	size_t elementSize;
} k_Allocator;

k_Allocator *k_GetAllocator(size_t elementSize);
