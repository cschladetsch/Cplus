#include <memory.h>
#include <stdlib.h>

#include "Foo.Generated.h"

void Construct(k_Any where, k_Any args)
{
	x_Foo *foo = (x_Foo *)where;
	memset(foo, 0, sizeof(x_Foo));

	foo->GetTwice = x_Foo_GetTwice;
}

k_Any New(k_Any args)
{
	x_Foo *self = (x_Foo *)malloc(sizeof(x_Foo));
	Construct(self, args);
	self->base.allocated = true;
	return self;
}

void Destroy(k_Any where)
{
	x_Foo *self = (x_Foo *)where;
	x_Foo_Destroy(self);
	if (self->base.allocated)
		free(self);
}

k_Allocator x_Foo_Alloc = { New, Construct, Destroy, sizeof(x_Foo) };

x_Foo *x_Foo_New()
{
	return (x_Foo *)New(0);
}

void x_Foo_Construct(x_Foo *self)
{
	Construct(self, 0);
}

void x_Foo_Destroy(x_Foo *self)
{
}

