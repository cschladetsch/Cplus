#include "KAI/Base.h"
#include "KAI/Memory/StackAllocator.h"

static void Construct(k_Any self, k_Any args)
{

}

static k_Any New(k_Any args)
{
	return null;
}

void k_StackAllocator_Construct(k_StackAllocator *self, char *buffer, size_t size, k_Allocator *alloc)
{
	self->buffer = buffer;
	self->allocator = alloc;
	self->size = size;
	self->current = 0;
}

char *k_StackAllocator_Alloc(k_StackAllocator *self, size_t size)
{
	if (self->current + size > self->size)
		return null;

	char *ptr = self->buffer + self->current;
	self->current += size;
	return ptr;
}

