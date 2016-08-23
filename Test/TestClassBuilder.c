#include <CUnit/Basic.h>
#include <Cplus/ForwardDeclarations.h>

typedef struct Foo_t Foo;
typedef struct Foo_t
{
	int num;

	int (*GetNum)(Foo *);
} Foo;

int Foo_GetNum(Foo *);

void TestClassBuilder()
{
//	k_Registry reg;
//	k_Registry_Construct(&reg);
//
//	k_ClassBuilder *cb = k_ClassBuilder_New();
//
//
//
//	k_ClassBuilder_Destroy(cb);
//	k_ClassBuilder_Destroy(&reg);
}
