#include <stdlib.h>
#include <memory.h>
#include "KAI/Container/Vector.h"

static k_Any New(k_Any args)
{
	k_Vector *v = (k_Vector *)malloc(sizeof(k_Vector));
	memset(v, 0, sizeof(k_Vector));
	v->base.alloc = &k_Vector_Alloc;
}

static void Construct(k_Any where)
{
}

static void Destroy(k_Any args)
{
	k_Vector *v = (k_Vector *)args;
	k_Vector_Clear(v);
	v->base.alloc->destroy(v);
}

void k_Vector_Clear(k_Vector *self)
{
	k_Allocator *elementAlloc = self->elementAlloc;

	if (!elementAlloc)
		return;

	char *item = self->data;
	for (int n = 0; n < self->size; ++n, item += elementAlloc->elementSize)
		elementAlloc->destroy(item);
}

k_Allocator k_Vector_Alloc = { New, Construct, Destroy, sizeof(k_Vector) };
