#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "KAI/Config.h"
#include "KAI/ForwardDeclarations.h"
#include "KAI/Allocator.h"
#include "KAI/TypeNumber.h"

typedef struct k_Base_t
{
	k_Allocator *alloc;
	bool allocated;
} k_Base;
