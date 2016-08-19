#include <memory.h>
#include <stdlib.h>
#include <assert.h>

#include "KAI/Container/Vector.h"
#include "KAI/Container/List.h"

static void Construct(k_Any where, k_Any args)
{
	memset(where, 0, sizeof(k_List));
}

static k_Any New(k_Any args)
{
	k_List *list = (k_List *)malloc(sizeof(k_List));
	Construct(list, args);
	list->base.allocated = true;
	return list;
}

static void Destroy(k_Any where)
{
	k_List_Destroy((k_List *)where);
}

k_Allocator k_List_Alloc = { New, Construct, Destroy, sizeof(k_List) };

static k_List *NewList()
{
	return (k_List *)New(0);
}

k_List *k_List_New(size_t size)
{
	k_List *list = NewList();
	list->itemAllocator = k_GetAllocator(size);
	return list;
}

k_List *k_List_New2(const k_Allocator *alloc)
{
	k_List *list = NewList();
	list->itemAllocator = alloc;
	return list;
}

static void FreeList(k_List_Node *head, k_Destroy_Function destroy)
{
	for (k_List_Node *node = head; node != NULL; )
	{
		k_List_Node *next = node->next;
		if (destroy)
			destroy(node);

		free(node);
		node = next;
	}
}

void k_List_Destroy(k_List *self)
{
	FreeList(self->head, self->itemAllocator->destroy);
	FreeList(self->pool, NULL);      // items in the pool have already been destroyed

	if (self->base.allocated)
		free(self);
}

static k_List_Node *NewNode(k_List *self)
{
	const k_Allocator *elemAlloc = self->itemAllocator;
	if (elemAlloc->new)
		return (k_List_Node *)elemAlloc->new(0);

	k_List_Node *node = (k_List_Node *)malloc(elemAlloc->elementSize);
	if (elemAlloc->construct)
	{
		elemAlloc->construct(node, self);
		return node;
	}

	memset(node, 0, elemAlloc->elementSize);
	return node;
}

size_t k_List_Size(k_List *self)
{
	size_t size = 0;
	for (k_List_Node *node = self->head; node; node = node->next)
		++size;

	return size;
}

bool k_List_Empty(k_List *self)
{
	return self->head == NULL;
}

static k_List_Node *GetFreeNode(k_List *self)
{
	k_List_Node *node = 0;

	if (self->pool != NULL)
	{
		node = self->pool;
		self->pool = node->next;

		if (self->itemAllocator->construct)
		{
			self->itemAllocator->construct(node, self);
		}
	}
	else
	{
		node = NewNode(self);
	}

	return node;
}

static void PushBack(k_List *self, k_List_Node *node)
{
	node->prev = self->tail;
	node->next = NULL;

	if (self->tail)
		self->tail->next = node;

	self->tail = node;

	if (self->head == NULL)
		self->head = node;
}

k_List_Node *k_List_PushBack(k_List *self)
{
	k_List_Node *node = GetFreeNode(self);

	PushBack(self, node);

	return node;
}

static void Release(k_List *self, k_List_Node *node)
{
	if (self->itemAllocator->destroy)
		self->itemAllocator->destroy(node);

	node->next = self->pool;
	self->pool = node;
}

void k_List_PopFront(k_List *self)
{
	assert(self->head != NULL);
	if (self->head == NULL)
		return;

	k_List_Node *oldHead = self->head;
	k_List_Node *head = self->head->next;
	if (head)
		head->prev = NULL;

	if (self->tail == self->head)
		self->tail = self->head = NULL;
	else
		self->head = head;

	Release(self, oldHead);
}

void k_List_PopBack(k_List *self)
{
	if (self->tail == NULL)
		return;

	k_List_Node *oldTail = self->tail;
	k_List_Node *tail = self->tail->prev;
	if (tail)
		tail->next = NULL;

	if (self->tail == self->head)
		self->tail = self->head = NULL;
	else
		self->tail = tail;

	Release(self, oldTail);
}

void k_List_Iterate(k_List *list, void (*fun)(k_List_Node *))
{
	for (k_List_Node *node = list->head; node != NULL; node = node->next)
		fun(node);
}
