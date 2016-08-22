#pragma once

#include "Config.h"
#include "Memory.h"

// Allocate a new item
typedef k_Any (*k_New_Function)(k_Any args);

// Construct an item in-place
typedef void (*k_Construct_Function)(k_Any where, k_Any args);

// Copy an item from left to right
typedef void (*k_Copy_Function)(k_Any left, k_Any right);

// Destroy an item (but not release memory of the item)
typedef void (*k_Destroy_Function)(k_Any);

// Release the memory used by the item itself
typedef void (*k_Free_Function)(k_Any);

// An object used to make other objects.
typedef struct k_Allocator_t
{
	k_New_Function new;
	k_Construct_Function construct;
	k_Destroy_Function destroy;
	k_Copy_Function copy;
	k_Free_Function free;
	size_t size;
}
k_Allocator;

k_Allocator *k_GetAllocator(size_t elementSize);

void k_Containers_Init();
void k_Containers_TearDown();

