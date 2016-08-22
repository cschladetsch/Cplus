#include <CUnit/Basic.h>

#include "KAI/Memory/StackAllocator.h"

void TestStackAllocator()
{
	char buffer[1024];
	k_StackAllocator alloc;
	k_StackAllocator_Construct(&alloc, buffer, sizeof(buffer));

	k_Vector vector;
	k_Vector_Construct2(&vector, (k_Allocator *)&alloc);


}
