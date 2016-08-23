#pragma once

#include <Cplus/Registry.h>
#include <Cplus/System/String.h>
#include "Cplus/Base.h"
#include "Cplus/Type/TypeNumber.h"

typedef struct k_FileLocation_t
{
	k_String fileName;
	int lineNumber;
	int column;
} k_FileLocation;

typedef struct k_Class_t
{
	k_Base base;
	k_Registry *registry;
	k_String name;
	k_TypeNumber typeNumber;
	k_Vector properties;
	k_Vector methods;
	k_Allocator *allocator;
	k_Pool *pool;
} k_Class;

k_Class *k_Class_New(k_Registry *);
void k_Class_Destroy(k_Class *);

void k_Class_Instance_Construct(k_Class *, k_Any, ...);
k_Any k_Class_Instance_New(k_Class *, ...);
k_Any k_Class_Instance_New2(k_Class *, k_Allocator *, ...);
void k_Class_Instance_Destroy(k_Class *, k_Any);



