#pragma once

#include "KAI/Base.h"


typedef struct k_Result_t k_Result;
typedef struct k_Result_t
{
	k_Base base;
//	k_Status status;
	k_Any value;

	k_String (*ToString)(k_Result *);
} k_Result;

typedef struct x_Foo_t x_Foo;
typedef struct x_Foo_t
{
	k_Base base;

	int num;

	k_Result (*Invoke)(x_Foo *, const char *, ...);
	k_Result (*GetProperty)(x_Foo *, const char *);
	k_Result (*SetProperty)(x_Foo *, const  char *, k_Any);

	int (*GetTwice)(x_Foo *);
	int (*Add)(x_Foo *, int);
} x_Foo;

extern k_Allocator x_Foo_Alloc;

x_Foo *x_Foo_New();
void x_Foo_Construct(x_Foo *);
void x_Foo_Destroy(x_Foo *);

int x_Foo_GetTwice(x_Foo *);
int x_Foo_Add(x_Foo *, int);

k_Result x_Foo_Invoke(x_Foo *, const char *method, ...);
k_Result x_Foo_GetProperty(x_Foo *, const char *property);
k_Result x_Foo_SetProperty(x_Foo *, const char *property, k_Any);

