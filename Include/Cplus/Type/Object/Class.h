#pragma once

#include <Cplus/Registry.h>
#include <Cplus/System/String.h>
#include "Cplus/Base.h"
#include "Cplus/Type/TypeNumber.h"

typedef struct k_Class_t
{
	k_Base base;
	k_Registry registry;
	k_String name;
	k_TypeNumber typeNumber;
	k_Vector properties;
	k_Vector methods;
	k_Allocator *allocator;
	k_Pool *pool;
} k_Class;

extern k_Allocator k_Class_Alloc;
