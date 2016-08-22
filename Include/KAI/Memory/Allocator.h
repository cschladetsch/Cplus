#pragma once

#include "KAI/Memory/Config.h"

// Allocate a new item
typedef k_Any (*k_New_Function)(k_Any args);
typedef void (*k_Construct_Function)(k_Any where, k_Any args);
typedef void (*k_Destroy_Function)(k_Any);

// An object used to make other objects.
typedef struct k_Allocator_t
{
	k_New_Function new;
	k_Construct_Function construct;
	k_Destroy_Function destroy;
	size_t size;
}
k_Allocator;

k_Allocator *k_GetAllocator(size_t elementSize);

void k_Containers_Init();
void k_Containers_TearDown();

