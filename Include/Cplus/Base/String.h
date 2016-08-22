#pragma once

#include "Cplus/Base.h"
#include "Cplus/Sys/Container/Vector.h"
#include "Cplus/Sys/String_Slice.h"

typedef struct k_String_t
{
	k_Base base;
	k_Vector str;
} k_String;

extern k_Allocator k_String_Alloc;

k_String *k_String_New();
k_String *k_String_New2(const char *);
k_String *k_String_New3(const k_Allocator *);

void k_String_Construct(k_String *);
void k_String_ConstructAlloc(k_String *, k_Allocator *);
void k_String_ConstructCstr(k_String *, const char *);
void k_String_ConstructCstrAlloc(k_String *, k_Allocator *alloc, const char *);
void k_String_Construct3(k_String *, const k_Allocator *);

void k_String_Destroy(k_String *);

size_t k_String_Length(const k_String *);
const char *k_String_Chars(const k_String *);

void k_String_Concat(k_String *result, const k_String *, const k_String *);
void k_String_ConcatCstr(k_String *result, const k_String *, const char *);
void k_String_Append(k_String *, char);

bool k_String_Equiv(const k_String *, const k_String *);
bool k_String_Less(const k_String *, const k_String *);

k_String_Slice k_String_MakeSlice(const k_String *, size_t start, size_t end);
void k_String_Format(k_String *, const char *, ...);

void k_String_Trim(k_String *);