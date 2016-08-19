#include <CUnit/Basic.h>

#include "Foo.Generated.h"

void TestFoo()
{
	x_Foo *foo = x_Foo_New();

	foo->num = 2;

	CU_ASSERT_EQUAL(foo->GetTwice(foo), 4);
}

