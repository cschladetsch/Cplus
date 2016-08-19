#include "Foo.Generated.h"

int x_Foo_GetTwice(x_Foo *self)
{
	return self->num*2;
}

int x_Foo_Add(x_Foo *self, int val)
{
	return self->num + val;
}
