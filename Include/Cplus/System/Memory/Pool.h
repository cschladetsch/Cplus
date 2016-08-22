#pragma once

#include "Cplus/Builtin/Container/Vector.h"

typedef struct k_Pool_t
{
	k_Base base;
	k_Vector *pools;

} k_Pool;
extern k_Allocator k_Pool_Alloc;

k_Any k_Pool_New(k_Pool *);
void k_Pool_Free(k_Pool *, k_Any);

