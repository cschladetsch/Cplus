#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include "KAI/Container/Vector.h"

static void Construct(k_Any where, k_Any args);

static k_Any New(k_Any args)
{
	k_Any store = malloc(sizeof(k_Vector));
	Construct(store, args);
	return store;
}

static void Construct(k_Any store, k_Any args)
{
	k_Vector *v = (k_Vector *)store;
	memset(v, 0, sizeof(k_Vector));
	v->base.alloc = &k_Vector_Alloc;
	v->elementAlloc = (k_Allocator *)args;
}

static void Destroy(k_Any vector)
{
	k_Vector *v = (k_Vector *)vector;
	k_Vector_Clear(v);
}

k_Allocator k_Vector_Alloc = { New, Construct, Destroy, sizeof(k_Vector) };


k_Vector *k_Vector_New(int elementSize)
{
	return k_Vector_New2(k_GetAllocator(elementSize));
}

k_Vector *k_Vector_New2(k_Allocator *elementAllocator)
{
	return (k_Vector *)k_Vector_Alloc.new(elementAllocator);
}

void k_Vector_Destroy(k_Vector *self)
{
	k_Vector_Clear(self);
	free(self->data);
	self->data = NULL;
	self->size = 0;
}

static void k_Vector_DestroyElement(k_Vector *self, k_Any item)
{
	if (!self->elementAlloc || !self->elementAlloc->destroy)
		return;

	self->elementAlloc->destroy(item);
}

void k_Vector_Clear(k_Vector *self)
{
	k_Allocator *elementAlloc = self->elementAlloc;

	if (elementAlloc && elementAlloc->destroy)
	{
		char *item = self->data;
		for (int n = 0; n < self->size; ++n, item += elementAlloc->elementSize)
			elementAlloc->destroy(item);
	}

	self->size = 0;
}

int k_Vector_Size(k_Vector *self)
{
	return self->size;
}

void k_Vector_Swap(k_Vector *a, k_Vector *b)
{
	k_Vector tmp = *a;
	*a = *b;
	*b = tmp;
}

void k_Vector_Reserve(k_Vector *self, int newMax)
{
	assert(newMax >= 0);
	if (newMax <= self->reserved)
		return;

	int elementSize = self->elementAlloc->elementSize;
	k_Any data = malloc(newMax*elementSize);
	memcpy(data, self->data, self->size*elementSize);
	self->data = data;
	self->reserved = newMax;
}

k_Any k_Vector_At(k_Vector *self, int index)
{
	assert(index < self->size);
	if (index >= self->size)
		return NULL;

	return self->data + index*self->elementAlloc->elementSize;
}

k_Any k_Vector_Begin(k_Vector *self)
{
	return self->data;
}

k_Any k_Vector_End(k_Vector *self)
{
	return self->data + self->elementAlloc->elementSize*self->size;
}

k_Any k_Vector_Back(k_Vector *self)
{
	assert(self->size > 0);
	if (self->size == 0)
		return NULL;

	return self->data + self->elementAlloc->elementSize*(self->size - 1);
}

k_Any k_Vector_Front(k_Vector *self)
{
	assert(self->size > 0);
	if (self->size == 0)
		return NULL;

	return self->data;
}

int k_Max_int(int a, int b)
{
	return a > b ? a : b;
}

void k_Vector_PushBack(k_Vector *self, k_Any element)
{
	if (self->size == self->reserved)
		k_Vector_Reserve(self, k_Max_int(8, self->size*2));

	int elemSize = self->elementAlloc->elementSize;
	memcpy(k_Vector_End(self), element, elemSize);
	self->size++;
}

void k_Vector_PopBack(k_Vector *self)
{
	assert(self->size > 0);
	if (self->size == 0)
		return;

	k_Vector_DestroyElement(self, k_Vector_Back(self));
	self->size--;
}

void k_Vector_Iterate(k_Vector *self, void (*fun)(k_Any))
{
	for (char *item = self->data; item < self->data + self->size; item += self->elementAlloc->elementSize)
		fun(item);
}

void k_Vector_Sort(k_Vector *self, int (*compare)(const void *, const void *))
{
	qsort(self->data, self->size, self->elementAlloc->elementSize, compare);
}
