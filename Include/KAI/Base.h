#pragma once

#include "KAI/Config.h"
#include "KAI/ForwardDeclarations.h"
#include "KAI/Memory/Memory.h"
#include "KAI/Memory/Allocator.h"
#include "KAI/Type/TypeNumber.h"

// Common to all system types.
typedef struct k_Base_t
{
	k_Allocator *alloc;
	bool allocated;
} k_Base;

// I am tied of yelling
#define null 0
