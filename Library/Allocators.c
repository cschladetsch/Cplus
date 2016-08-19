#include <stdlib.h>
#include <memory.h>
#include "KAI/Allocator.h"
#include "KAI/Container/Vector.h"

static k_Vector *k_allocators;

void k_Containers_Init()
{
	k_allocators = (k_Vector *)malloc(sizeof(k_Vector));
	memset(k_allocators, 0, sizeof(k_Vector));
	k_Allocator *elemAlloc = (k_Allocator *)malloc(sizeof(k_Allocator));
	memset(elemAlloc, 0, sizeof(k_Allocator));
	elemAlloc->size = sizeof(k_Allocator *);
	k_allocators->itemAlloc = elemAlloc;
}

void k_Containers_Teardown()
{
	k_Vector_Destroy(k_allocators);
	free((k_Allocator *)k_allocators->itemAlloc);
	k_allocators = null;
}

k_Allocator *k_GetAllocator(size_t elementSize)
{
	for (int n = 0; n < k_allocators->size; ++n)
	{
		k_Allocator *alloc = (k_Allocator *)(k_Vector_At(k_allocators, n));
		if (alloc->size == elementSize)
			return alloc;
	}

	k_Allocator *allocator = (k_Allocator *)malloc(sizeof(k_Allocator));
	memset(allocator, 0, sizeof(k_Allocator));
	allocator->size = elementSize;
	k_Vector_PushBack(k_allocators, allocator);

	return allocator;
}

