#pragma once

#include "KAI/Container/Vector.h"

// Map.h
typedef struct k_Map_t
{
	k_Base base;
	k_Vector *buckets;
	int (*Hash)(k_Any);
	bool (*Equiv)(k_Any, k_Any);
} k_Map;
extern k_Allocator k_Map_Alloc;

void k_Map_Insert(k_Map *, k_Any, k_Any);
void k_Map_Erase(k_Map *, k_Any);
k_Any k_Map_Find(k_Map *, k_Any);
void k_Map_Iterate(k_Map *, void (*fun)(k_Any, k_Any));
