#include <CUnit/Basic.h>

#include "Cplus/Container/Vector.h"

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


