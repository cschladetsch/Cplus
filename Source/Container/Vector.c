#include <stdlib.h>
#include <memory.h>

#include "Cplus/Debug/Assert.h"
#include "Cplus/Container/Vector.h"

static void Construct(k_Any store, k_Any itemAlloc)
{
	k_Vector *self = (k_Vector *)store;
	memset(self, 0, sizeof(k_Vector));
	self->base.alloc = &k_Vector_Alloc;
	self->itemAlloc = (k_Allocator *)itemAlloc;
}

static k_Any New(k_Any itemAlloc)
{
	k_Vector *self = (k_Vector *)k_MallocRaw(sizeof(k_Vector));
	Construct(self, itemAlloc);
	self->base.allocated = true;
	return self;
}

static void Destroy(k_Any vector)
{
	k_Vector_Clear((k_Vector *)vector);
}

k_Allocator k_Vector_Alloc = { New, Construct, Destroy, 0, 0, sizeof(k_Vector) };

k_Vector *k_Vector_New(size_t elementSize)
{
	return k_Vector_New2(k_GetAllocator(elementSize));
}

k_Vector *k_Vector_New2(const k_Allocator *elementAllocator)
{
	return (k_Vector *)New((k_Any)elementAllocator);
}

void k_Vector_Destroy(k_Vector *self)
{
	k_Vector_Clear(self);
	self->base.alloc->free(self);
}

static void DestroyElement(k_Vector *self, k_Any item)
{
	k_Destroy_Function destroy = self->itemAlloc->destroy;
	if (destroy)
		destroy(item);
}

void k_Vector_Clear(k_Vector *self)
{
	const k_Allocator *alloc = self->itemAlloc;
	k_Destroy_Function destroy = alloc->destroy;
	if (destroy)
	{
		char *item = self->data;
		size_t size = self->size;
		size_t elementSize = alloc->size;
		for (size_t n = 0; n < size; ++n, item += elementSize)
			destroy(item);
	}

	self->size = 0;
}

size_t k_Vector_Size(k_Vector *self)
{
	return self->size;
}

void k_Vector_Swap(k_Vector *a, k_Vector *b)
{
	k_Vector tmp = *a;
	*a = *b;
	*b = tmp;
}

void k_Vector_Reserve(k_Vector *self, size_t newMax)
{
	if (newMax <= self->reserved)
		return;

	size_t elementSize = self->itemAlloc->size;
	k_Any data = k_MallocRaw(newMax*elementSize);
	memcpy(data, self->data, self->size*elementSize);
	self->data = data;
	self->reserved = newMax;
}

k_Any k_Vector_At(k_Vector *self, size_t index)
{
	k_Assert(index < self->size);
	if (index >= self->size)
		return null;

	return self->data + index*self->itemAlloc->size;
}

k_Any k_Vector_Begin(k_Vector *self)
{
	return self->data;
}

k_Any k_Vector_End(k_Vector *self)
{
	return self->data + self->itemAlloc->size*self->size;
}

k_Any k_Vector_Back(k_Vector *self)
{
	k_Assert(self->size > 0);
	if (self->size == 0)
		return null;

	return self->data + self->itemAlloc->size*(self->size - 1);
}

k_Any k_Vector_Front(k_Vector *self)
{
	k_Assert(self->size > 0);
	if (self->size == 0)
		return null;

	return self->data;
}

size_t k_Max_size_t(size_t a, size_t b)
{
	return a > b ? a : b;
}

void k_Vector_PushBack(k_Vector *self, k_Any element)
{
	if (self->size == self->reserved)
		k_Vector_Reserve(self, k_Max_size_t(8, self->size * 2));

	size_t elemSize = self->itemAlloc->size;
	memcpy(k_Vector_End(self), element, elemSize);
	self->size++;
}

void k_Vector_PopBack(k_Vector *self)
{
	k_Assert(self->size > 0);
	if (self->size == 0)
		return;

	DestroyElement(self, k_Vector_Back(self));
	self->size--;
}

void k_Vector_Iterate(k_Vector *self, void (*fun)(k_Any))
{
	size_t esize = self->itemAlloc->size;
	size_t size = self->size;
	char *item = self->data;
	for (int n = 0; n < size; ++n, item += esize)
		fun(item);
}

void k_Vector_SortPOD(k_Vector *self, int (*compare)(const void *, const void *))
{
	qsort(self->data, self->size, self->itemAlloc->size, compare);
}
