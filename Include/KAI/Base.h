#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "KAI/Config.h"
#include "KAI/ForwardDeclarations.h"
#include "KAI/Memory.h"
#include "KAI/Allocator.h"
#include "KAI/TypeNumber.h"

// Common to all system types.
typedef struct k_Base_t
{
	k_Allocator *alloc;
	bool allocated;
} k_Base;

// I am tied of yelling
#define null 0
