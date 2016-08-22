#pragma once

#include "Object.h"

typedef struct k_Value_t
{
	k_Object object;
	char value[];
} k_Value;
