#include <CUnit/Basic.h>

#include "Cplus/Container/List.h"

int nodesConstructed;

void ConstructMyNode(k_Any any, k_Any args)
{
	++nodesConstructed;
//	printf("\nConstructing %p (%p)\n", any, args);
}

void DestroyMyNode(k_Any any)
{
	--nodesConstructed;
//	printf("\nDestroying %p\n", any);
}

void Set(k_Any load, int val)
{
	*(int *)load = val;
}

int Get(k_Any load)
{
	return *(int *)load;
}

void Print(k_Any load)
{
	printf("%d\n", Get(load));
}

int list_sum;

void Sum(k_Any load)
{
	list_sum += Get(load);
}

void TestList()
{
	k_Allocator alloc = { null, ConstructMyNode, DestroyMyNode, 0, 0, sizeof(int) };
	k_List *list = k_List_New2(&alloc);

	for (int n = 0; n < 4; ++n)
	{
		k_List_Node *node = k_List_PushBack(list);
		Set(node->payload, n + 1);
	}

	CU_ASSERT_EQUAL(k_List_Size(list), 4);

	k_List_Iterate(list, Sum);
	CU_ASSERT_EQUAL(list_sum, 1 + 2 + 3 + 4);

	k_List_PopBack(list);

	list_sum = 0;
	k_List_Iterate(list, Sum);
	CU_ASSERT_EQUAL(list_sum, 1 + 2 + 3);

	k_List_PopFront(list);

	CU_ASSERT_EQUAL(k_List_Size(list), 2);

	list_sum = 0;
	k_List_Iterate(list, Sum);
	CU_ASSERT_EQUAL(list_sum, 2 + 3);

	k_List_Destroy(list);

	CU_ASSERT_EQUAL(0, nodesConstructed);
}




