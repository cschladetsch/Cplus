#pragma once

#include "KAI/Base.h"

// A dynamic array of PODs
typedef struct k_Vector_t
{
	k_Base base;
	k_Allocator *elementAlloc;
	size_t size;
	size_t reserved;
	char *data;
} k_Vector;

extern k_Allocator k_Vector_Alloc;

// Make a new Vector on the heap
k_Vector *k_Vector_New(size_t elementSize);
k_Vector *k_Vector_New2(const k_Allocator *elementAllocator);

// Construct a Vector in-place
void k_Vector_Construct(k_Vector *, size_t elementSize);
void k_Vector_Construct2(k_Vector *, const k_Allocator *elementAllocator);

// Destroy a Vector in-place, and free it if it is on the heap
void k_Vector_Destroy(k_Vector *);

// Return the number of items in the Vector
size_t k_Vector_Size(k_Vector *);

// Swap a vector with another
void k_Vector_Swap(k_Vector *, k_Vector *);

// Destroy all items in the Vector
void k_Vector_Clear(k_Vector *);

// Ensure there is at lease newMax items available in the Vector
void k_Vector_Reserve(k_Vector *, size_t newMax);

// Return the start of the Vector items
k_Any k_Vector_Begin(k_Vector *);

// Return the end of the Vector (one past the last item)
k_Any k_Vector_End(k_Vector *);

// Return the item at the given index
k_Any k_Vector_At(k_Vector *, size_t index);

// Return the last item
k_Any k_Vector_Back(k_Vector *);

// Return the first item
k_Any k_Vector_Front(k_Vector *);

// Copy an item to the end of the Vector
void k_Vector_PushBack(k_Vector *, k_Any);

// Destroy the last item
void k_Vector_PopBack(k_Vector *);

// Return true if one Vector is lexographically less than another
bool k_Vector_Less(k_Vector *, k_Vector *, bool (*)(k_Any, k_Any));

// Return true if both Vectors are the same size, and all the items are considered equivalent
bool k_Vector_Equiv(k_Vector *, k_Vector *, bool (*)(k_Any, k_Any));

// Iterate over all items in the Vector
void k_Vector_Iterate(k_Vector *, void (*fun)(k_Any));

// Sort all items in the Vector
void k_Vector_Sort(k_Vector *, int (*compare)(const void *, const void *));

