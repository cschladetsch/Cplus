#pragma once

#include "KAI/Memory/Allocator.h"

typedef struct k_StackAllocator_t
{
	// where on stack to allocate from
	char *buffer;

	// total size of buffer
	size_t size;

	// current top of usage
	size_t current;

	// used to construct/delete items
	k_Allocator *allocator;

}
k_StackAllocator;

void k_StackAllocator_Construct(k_StackAllocator *, char *, size_t);
void k_StackAllocator_ConstructAlloc(k_StackAllocator *, char *, size_t, k_Allocator *alloc);

char *k_StackAllocator_Alloc(k_StackAllocator *, size_t);

