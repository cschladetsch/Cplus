#pragma once

#include "KAI/Container/Vector.h"

typedef int (*k_Map_HashFunction)(k_Any);
typedef bool (*k_Map_HashEquivFunction)(k_Any, k_Any);

typedef struct k_Map_t
{
	k_Base base;
	k_Vector *buckets;
	k_Map_HashFunction hash;
	k_Map_HashEquivFunction equiv;
	k_Allocator *bucketItemAllocator;
	k_Allocator *keyAllocator;
	k_Allocator *valueAllocator;
} k_Map;

extern k_Allocator k_Map_Alloc;

k_Map *k_Map_New(k_Allocator *keyAlloc, k_Allocator *valueAlloc, k_Map_HashFunction, k_Map_HashEquivFunction);
void k_Map_Destroy(k_Map *);

void k_Map_Insert(k_Map *, k_Any, k_Any);
void k_Map_Erase(k_Map *, k_Any);
k_Any k_Map_Find(k_Map *, k_Any);
void k_Map_Iterate(k_Map *, void (*fun)(k_Any, k_Any));
