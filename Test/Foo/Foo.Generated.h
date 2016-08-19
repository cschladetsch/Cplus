#pragma once

#include "KAI/Base.h"

typedef struct x_Foo_t x_Foo;
typedef struct x_Foo_t
{
	k_Base base;

	int num;

	int (*GetTwice)(x_Foo *);
} x_Foo;

extern k_Allocator x_Foo_Alloc;

x_Foo *x_Foo_New();
void x_Foo_Construct(x_Foo *);
void x_Foo_Destroy(x_Foo *);

int x_Foo_GetTwice(x_Foo *);
