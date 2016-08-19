
#include <memory.h>
#include <stdlib.h>
#include "KAI/Container/Map.h"
#include "KAI/Container/List.h"
#include "KAI/Container/Vector.h"

#define INIT_BUCKET_COUNT 37

static void MakeBuckets(k_Map *);
static k_List MakeBucket(k_Map *);

static void Construct(k_Any where, k_Any args)
{
	k_Map *map = (k_Map *)where;
	memset(map, 0, sizeof(k_Map));
	map->buckets = k_Vector_New(sizeof(k_List));    // a Vector of lists, stored by value
	MakeBuckets(map);
}

static k_Any New(k_Any args)
{
	k_Map *map = malloc(sizeof(k_Map));
	Construct(map, args);
	map->base.allocated = true;
	return map;
}

static void Destroy(k_Any where)
{
	k_Map_Destroy((k_Map *)where);
}

k_Allocator k_Map_Alloc = { New, Construct, Destroy, sizeof(k_Map) };

typedef struct Pair_t
{
	k_List_Node node;
	k_Any key;
	k_Any value;
} Pair;

k_Map *k_Map_New(k_Allocator *keyAlloc, k_Allocator *valueAlloc, k_Map_HashFunction hash, k_Map_HashEquivFunction equiv)
{
	k_Map *map = (k_Map *)New(0);

	map->hash = hash;
	map->equiv = equiv;

	return map;
}

static void MakeBuckets(k_Map *self)
{
	for (int n = 0; n < INIT_BUCKET_COUNT; ++n)
	{
//		k_Vector_PushBack(self->buckets, &MakeBucket(self));
	}
}

static k_List MakeBucket(k_Map *map)
{
	k_List list;
	k_List_Alloc.construct(&list, 0);
	list.elementAllocator = k_GetAllocator(sizeof(Pair));
	return list;
}

void DestroyBucket(k_Any where)
{
	k_List_Destroy((k_List *)where);
}

void k_Map_Destroy(k_Map *self)
{
	k_Vector_Iterate(self->buckets, DestroyBucket);
	k_Vector_Destroy(self->buckets);
	self->buckets = NULL;

	if (self->base.allocated)
		free(self);
}

void k_Map_Insert(k_Map *self, k_Any key, k_Any value);
void k_Map_Erase(k_Map *, k_Any);
k_Any k_Map_Find(k_Map *, k_Any);
void k_Map_Iterate(k_Map *, void (*fun)(k_Any, k_Any));

