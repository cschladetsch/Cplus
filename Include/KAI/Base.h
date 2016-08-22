#pragma once

#include "KAI/Memory/Allocator.h"

// Common to all system types.
typedef struct k_Base_t
{
	const k_Allocator *alloc;
	bool allocated;
} k_Base;

