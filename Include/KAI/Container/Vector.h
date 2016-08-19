#pragma once

#include "KAI/Base.h"

// Vector.h
typedef struct k_Vector_t
{
	k_Base base;
	k_Allocator *elementAlloc;
	int size;
	int reserved;
	char *data;
} k_Vector;

extern k_Allocator k_Vector_Alloc;

k_Vector *k_Vector_New(int elementSize);
k_Vector *k_Vector_New2(k_Allocator *elementAllocator);
void k_Vector_Destroy(k_Vector *);

int k_Vector_Size(k_Vector *);

void k_Vector_Swap(k_Vector *, k_Vector *);
void k_Vector_Clear(k_Vector *);
void k_Vector_Reserve(k_Vector *, int newMax);

k_Any k_Vector_Begin(k_Vector *);
k_Any k_Vector_End(k_Vector *);

k_Any k_Vector_At(k_Vector *, int index);
k_Any k_Vector_Back(k_Vector *);
k_Any k_Vector_Front(k_Vector *);

void k_Vector_PushBack(k_Vector *, k_Any);
void k_Vector_PopBack(k_Vector *);

void k_Vector_Iterate(k_Vector *, void (*fun)(k_Any));
void k_Vector_Sort(k_Vector *, int (*compare)(const void *, const void *));

void k_Containers_Init();
void k_Containers_Teardown();
