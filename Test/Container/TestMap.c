#include <CUnit/Basic.h>

#include "Cplus/Container/Map.h"

size_t HashInt(int *p)
{
	int n = *p;
	return (size_t)(n < 0 ? -n : n);
}

bool EquivInt(int *pa, int *pb)
{
	return *pa == *pb;
}

void TestMap()
{
//	k_Map *map = k_Map_New(k_GetAllocator(sizeof(int)), k_GetAllocator(sizeof(char *)), HashInt, EquivInt);
}


