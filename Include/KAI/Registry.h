#pragma once

#include "KAI/Container/Map.h"

typedef struct k_Registry_t
{
	k_Base base;
	k_Map *classes;
	k_Map *objects;
} k_Registry;
extern k_Allocator k_Registry_Alloc;

void k_Registry_Register(k_Registry *, k_Class *);

k_Value *k_Registry_Create(k_Registry *, k_TypeNumber type);
void k_Registry_Release(k_Registry *, k_Object *);

k_Value *k_Registry_Find(k_Registry *, k_InstanceNumber);
void k_Registry_GC(k_Registry *);

