#include <CUnit/Basic.h>

#include "KAI/Container/Vector.h"
#include "KAI/Container/List.h"
#include "KAI/Container/Map.h"

void TestVector()
{
	k_Vector *v = k_Vector_New(sizeof(int));

	int n = 1;
	k_Vector_PushBack(v, &n);

	n = 2;
	k_Vector_PushBack(v, &n);

	CU_ASSERT_EQUAL(2, k_Vector_Size(v));
	CU_ASSERT_EQUAL(1, *(int *)k_Vector_At(v, 0));
	CU_ASSERT_EQUAL(2, *(int *)k_Vector_At(v, 1));
	CU_ASSERT_EQUAL(1, *(int *)k_Vector_Front(v));
	CU_ASSERT_EQUAL(2, *(int *)k_Vector_Back(v));

	k_Vector_PopBack(v);
	CU_ASSERT_EQUAL(k_Vector_Front(v), k_Vector_Back(v));
	CU_ASSERT_EQUAL(1, *(int *)k_Vector_Front(v));
	CU_ASSERT_EQUAL(1, *(int *)k_Vector_Back(v));

	k_Vector_PopBack(v);
	CU_ASSERT_EQUAL(0, k_Vector_Size(v));
	for (n = 0; n < 128; ++n)
		k_Vector_PushBack(v, &n);

//	for (n = 0; n < 128; ++n)
//		CU_ASSERT_EQUAL(n, *(int *)k_Vector_At(v, n));

	CU_ASSERT_EQUAL(128, k_Vector_Size(v));
	k_Vector_Clear(v);
	CU_ASSERT_EQUAL(0, k_Vector_Size(v));

	k_Vector_Destroy(v);
}

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
	k_Allocator alloc = { null, ConstructMyNode, DestroyMyNode, sizeof(int) };
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

//	k_List_Destroy(list);
//
//	CU_ASSERT_EQUAL(0, nodesConstructed);
}

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

