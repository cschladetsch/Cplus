#include "Cplus/ForwardDeclarations.h"

#ifdef K_MEMORY_DEBUG_ALLOCATION
#define K_ALLOCATION_MAGIC_NUMBER 42
#endif

// Used as a base pointer for all allocations made by the system
typedef struct k_Allocation_Header_t
{
#ifdef K_MEMORY_DEBUG_ALLOCATION
	// magic number to guard against corruption
	char magic;
#endif

	// the type of the element(s)
	int type;

	// guard against multiple frees
	char freed;

	// the number of items allocated for
	long count;

	// this is passed back to client
	char ptr[];
} k_Allocation_Header;

typedef struct k_AllocationSource_t k_AllocationSource;

typedef k_Allocation_Header *(*k_AllocationSource_Alloc)(k_AllocationSource *, size_t numBytes);
typedef k_Any (*k_AllocationSource_Free)(k_AllocationSource *, k_Allocation_Header *);

// How to get memory. Can be from BSS, Stack or Heap
typedef struct k_AllocationSource_t
{
} k_AllocationSource;

