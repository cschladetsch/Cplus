#pragma once

#include "Cplus/Base.h"
#include "Cplus/Type/TypeNumber.h"
#include "Cplus/Builtin/Container/Vector.h"

// Class.h
typedef struct k_Class_t
{
	k_Base base;
	k_Registry *registry;
	k_String *name;
	k_TypeNumber typeNumber;
	k_Vector *properties;
	k_Vector *methods;
	k_Construct_Function create;
	k_Destroy_Function destroy;
	k_Pool *pool;
} k_Class;

extern k_Allocator k_Class_Alloc;
