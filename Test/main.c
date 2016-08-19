#include <CUnit/Basic.h>
#include "KAI/Allocator.h"

void TestVector();
void TestList();
void TestMap();

void TestFoo();
void TestFoo_Local();

int Start()
{
	k_Containers_Init();

	return 0;
}

int End()
{
	k_Containers_Teardown();

	return 0;
}

int main()
{
	CU_initialize_registry();

	CU_pSuite suite = CU_add_suite("Container Test", Start, End);

	CU_basic_set_mode(CU_BRM_VERBOSE);

	CU_add_test(suite, "TestVector", TestVector);
	CU_add_test(suite, "TestList", TestList);
	CU_add_test(suite, "TestMap", TestMap);

	CU_add_test(suite, "TestFoo", TestFoo);
	CU_add_test(suite, "TestFoo_Local", TestFoo_Local);

	CU_basic_run_tests();

	CU_cleanup_registry();

	return 0;
}
