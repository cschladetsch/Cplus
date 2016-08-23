#pragma once

#include "Cplus/Config.h"
#include "Cplus/ForwardDeclarations.h"
#include "Cplus/Memory/Allocator.h"
#include "Cplus/Memory/StackAllocator.h"

// Allocate without zeroing
k_Any k_MallocRaw(size_t size);

// Allocate, and zero the memory using memset
k_Any k_Malloc(size_t size);

// Reallocate
k_Any k_ReAlloc(k_Any, size_t size);

// Free
void k_Free(k_Any);
