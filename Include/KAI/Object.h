#pragma once

#include "KAI/Registry.h"

// Object.h
typedef struct k_Object_t
{
	k_Base base;
	k_Registry *registry;
	k_Class *class;
	k_InstanceNumber instanceNumber;
	bool isValue;
} k_Object;

extern k_Allocator k_Object_Alloc;

k_Value *k_Object_Deref(k_Object *);

void k_Object_Assign(k_Object *lhs, k_Object *rhs);

k_Object *k_Object_Duplicate(k_Object *);

k_String *k_Object_ToString(k_Object *);

void k_Object_Insert(k_Object *, k_StringStream *);
void k_Object_Extract(k_Object *, k_StringStream *);

k_Object *k_Object_Plus(k_Object *, k_Object *);
k_Object *k_Object_Multiply(k_Object *, k_Object *);

bool k_Object_Equiv(k_Object *, k_Object *);
bool k_Object_Less(k_Object *, k_Object *);
