#include <memory.h>
#include "Cplus/Sys/String.h"
#include "Cplus/Sys/Memory/Memory.h"

void Construct(k_Any where, k_Any args)
{
	k_String *self = (k_String *)where;
	memset(self, 0, sizeof(k_String));
	k_Vector_Construct(&self->str, sizeof(char));
}

k_Any New(k_Any args)
{
	k_String *self = (k_String *)k_Malloc(sizeof(k_String));
	Construct(self, args);
	return self;
}

void Destroy(k_Any where)
{
	k_String *self = (k_String *)where;
	k_Vector_Destroy(&self->str);
}

k_Allocator k_String_Alloc = { New, Construct, Destroy, sizeof(k_String) };

k_String *k_String_New()
{
	return null;
}

k_String *k_String_New2(const char *str)
{
	return null;
}

k_String *k_String_New3(const k_Allocator * alloc)
{
	return null;
}

void k_String_Construct(k_String *self)
{
}

void k_String_Construct2(k_String *self, const char *str)
{
}

void k_String_Construct3(k_String *self, const k_Allocator *alloc)
{
}

void k_String_Destroy(k_String *self)
{
}

size_t k_String_Length(const k_String *self)
{
	return self->str.size;
}

const char *k_String_Chars(const k_String *self)
{
	return null;
}

void k_String_Concat(k_String *result, const k_String *left, const k_String *right)
{
}

void k_String_Append(k_String *self, char ch)
{
}

bool k_String_Equiv(const k_String *self, const k_String *other)
{
	return false;
}

bool k_String_Less(const k_String *self, const k_String *other)
{
	return false;
}

k_String_Slice k_String_MakeSlice(const k_String *self, size_t start, size_t end)
{
	k_String_Slice slice;
	return slice;
}

void k_String_Format(k_String *self, const char *fmt, ...)
{
}

void k_String_Trim(k_String *self)
{
}


