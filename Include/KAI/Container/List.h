#pragma once

#include "KAI/Base.h"

// A generic node in a doubly-linked List
typedef struct k_List_Node_t
{
	struct k_List_Node_t *next, *prev;
	char payload[];
}
k_List_Node;

// A generic doubly linked list.
typedef struct k_List_t
{
	k_Base base;

	// used to construct and destroy payloads
	const k_Allocator *itemAllocator;

	// start and end of the list
	k_List_Node *head, *tail;

	// used to store freelist
	k_List_Node *pool;
}
k_List;

// how to construct and destroy lists
extern const k_Allocator k_List_Alloc;

// make a new list given element size. this implies
// the payload is a POD
k_List *k_List_New(size_t elementSize);

// make a new list given an allocator
k_List *k_List_New2(const k_Allocator *);

// Destroy all nodes in the list, and the list itelf
void k_List_Destroy(k_List *);

// Destroy all nodes in the list
void k_List_Clear(k_List *);

// Remove a range of items from the list
void k_List_EraseRange(k_List *self, k_List_Node *node, k_List_Node *end);

// Remove the given node from the list
void k_List_Erase(k_List *, k_List_Node *);

// Free items in pool
void k_List_Trim(k_List *);

// Return the size of a list
// O(N)
size_t k_List_Size(k_List *);

// Add a node to end of list, returning it.
k_List_Node *k_List_PushBack(k_List *);

// Add a node to start of list, returning it.
k_List_Node *k_List_PushFront(k_List *);

// Remove the first node in the list
void k_List_PopFront(k_List *);

// Remove the last node in the list
void k_List_PopBack(k_List *);

// Iterate through all nodes in the list
void k_List_Iterate(k_List *, void (*)(k_Any));

