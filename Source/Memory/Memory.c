#include <stdlib.h>
#include <memory.h>

#include "Cplus/System/Memory/Memory.h"

// define to provide detailed logging info for memory usage
//#define K_MEMORY_TRACE

k_Any k_MallocRaw(size_t size)
{
	return malloc(size);
}

k_Any k_Malloc(size_t size)
{
	k_Any ptr = k_MallocRaw(size);
	memset(ptr, 0, size);
	return ptr;
}

k_Any k_ReAlloc(k_Any ptr, size_t size)
{
	return realloc(ptr, size);
}

void k_Free(k_Any ptr)
{
	free(ptr);
}

