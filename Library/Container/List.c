#include <memory.h>
#include <assert.h>

#include "KAI/Container/Vector.h"
#include "KAI/Container/List.h"

static void Release(k_List *self, k_List_Node *node);

static void Construct(k_Any where, k_Any args)
{
	memset(where, 0, sizeof(k_List));
}

static k_Any New(k_Any args)
{
	k_List *list = (k_List *)k_MallocRaw(sizeof(k_List));
	Construct(list, args);
	list->base.allocated = true;
	return list;
}

static void Destroy(k_Any where)
{
	k_List_Destroy((k_List *)where);
}

const k_Allocator k_List_Alloc = { New, Construct, Destroy, sizeof(k_List) };

static k_List *NewList()
{
	return (k_List *)New(0);
}

k_List *k_List_New(size_t itemSize)
{
	k_List *list = NewList();
	list->itemAllocator = k_GetAllocator(itemSize);
	return list;
}

k_List *k_List_New2(const k_Allocator *alloc)
{
	k_List *list = NewList();
	list->itemAllocator = alloc;
	return list;
}

void k_List_Destroy(k_List *self)
{
	k_List_Clear(self);
	k_List_Trim(self);

	if (self->base.allocated)
		// TODO: use allocator to free resources
		k_Free(self);
}

void k_List_Clear(k_List *self)
{
	k_List_EraseRange(self, self->head, NULL);
}

void k_List_Trim(k_List *self)
{
	for (k_List_Node *node = self->pool; node; /* nop */)
	{
		k_List_Node *next = node->next;
		// TODO: use allocator to free resources
		k_Free(node);
		node = next;
	}
}

void k_List_EraseRange(k_List *self, k_List_Node *node, k_List_Node *end)
{
	while (node != end)
	{
		k_List_Node *next = node->next;
		Release(self, node);
		node = next;
	}
}

static k_List_Node *NewNode(k_List *self)
{
	const k_Allocator *itemAlloc = self->itemAllocator;
	k_List_Node *new = (k_List_Node *)k_MallocRaw(sizeof(k_List_Node) + itemAlloc->size);
	memset(new, 0, sizeof(k_List_Node));

	k_Construct_Function construct = itemAlloc->construct;
	if (construct)
		construct(new->payload, self);

	return new;
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
	return self->head == null;
}

// Get a node: either by buying a new one from allocator, or from
// list of previously released nodes stored in self->pool.
static k_List_Node *GetNode(k_List *self)
{
	if (self->pool == null)
		return NewNode(self);

	k_List_Node *node = self->pool;
	self->pool = node->next;

	k_Construct_Function construct = self->itemAllocator->construct;
	if (construct)
		construct(node, self);

	return node;
}

static k_List_Node *PushBack(k_List *self, k_List_Node *node)
{
	node->prev = self->tail;
	node->next = null;

	if (self->tail)
		self->tail->next = node;

	self->tail = node;

	if (self->head == null)
		self->head = node;

	return node;
}

k_List_Node *k_List_PushBack(k_List *self)
{
	return PushBack(self, GetNode(self));
}

static void Release(k_List *self, k_List_Node *node)
{
	if (!node)
		return;

	k_Destroy_Function destroy = self->itemAllocator->destroy;
	if (destroy)
		destroy(node->payload);

	node->next = self->pool;
	self->pool = node;
}

void k_List_PopFront(k_List *self)
{
	assert(self->head != null);
	if (self->head == null)
		return;

	k_List_Node *head = self->head->next;
	Release(self, self->head);
	if (head)
		head->prev = null;

	if (self->tail == self->head)
		self->tail = self->head = null;
	else
		self->head = head;
}

void k_List_PopBack(k_List *self)
{
	if (self->tail == null)
		return;

	k_List_Node *tail = self->tail->prev;
	Release(self, self->tail);
	if (tail)
		tail->next = null;

	if (self->tail == self->head)
		self->tail = self->head = null;
	else
		self->tail = tail;
}

void k_List_Iterate(k_List *list, void (*fun)(k_Any))
{
	for (k_List_Node *node = list->head; node != null; node = node->next)
		fun(node->payload);
}

