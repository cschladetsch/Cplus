#include "Cplus/Sys/String_Slice.h"

void k_String_Slice_Construct(k_String_Slice *self, const char *start, const char *end)
{
	self->start = start;
	self->end = end;
}

size_t k_String_Slice_Length(const k_String_Slice *self)
{
	return self->end - self->start;
}

