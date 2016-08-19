#include <CUnit/Basic.h>

#include "Foo.Generated.h"

void TestFoo()
{
	x_Foo *foo = x_Foo_New();

	foo->num = 2;

	CU_ASSERT_EQUAL(foo->GetTwice(foo), 4);
	CU_ASSERT_EQUAL(foo->Add(foo, 3), 5);

	int val = 4;
	k_Result result = foo->Invoke(foo, "Add", 4);
	CU_ASSERT_EQUAL(6, (int)result.value);
}

