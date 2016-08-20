#include <memory.h>
#include <stdlib.h>
#include <stdarg.h>

#include "Foo.Generated.h"

void Construct(k_Any where, k_Any args)
{
	x_Foo *foo = (x_Foo *)where;
	memset(foo, 0, sizeof(x_Foo));

	foo->Invoke = x_Foo_Invoke;
	foo->GetProperty = x_Foo_GetProperty;
	foo->SetProperty = x_Foo_SetProperty;

	foo->GetTwice = x_Foo_GetTwice;
	foo->Add = x_Foo_Add;
}

k_Any New(k_Any args)
{
	x_Foo *self = (x_Foo *)k_Malloc(sizeof(x_Foo));
	Construct(self, args);
	self->base.allocated = true;
	return self;
}

void Destroy(k_Any where)
{
	x_Foo *self = (x_Foo *)where;
	x_Foo_Destroy(self);
	if (self->base.allocated)
		k_Free(self);
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
//	x_Bar_Destroy(bar);
}

k_Result x_Foo_Invoke(x_Foo *self, const char *method, ...)
{
	va_list ap;
	va_start(ap, method);

	k_Result result;
//	k_Result_Construct(&result);

	if (strcmp(method, "Add") == 0)
	{
		int val = va_arg(ap, int);
		int r = x_Foo_Add(self, val);
		result.value = (k_Any)r;
//		result.value = self->base.registry->New(Type_Number_Int, &r);
	}
	else
	{
//		result.status = K_STATUS_UNKNOWN_METHOD;
	}

	return result;
}

k_Result x_Foo_GetProperty(x_Foo *self, const char *property)
{
	k_Result result;
	return result;
}

k_Result x_Foo_SetProperty(x_Foo *self, const char *property, k_Any val)
{
	k_Result result;
	return result;
}
