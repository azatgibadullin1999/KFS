/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:35:58 by larlena           #+#    #+#             */
/*   Updated: 2025/09/25 23:14:40 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/mmap.h>

#define TINY_HEAP_ALLOCATION_SIZE ((size_t)(4 * getpagesize()))
#define TINY_BLOCK_SIZE ((size_t)(TINY_HEAP_ALLOCATION_SIZE / 128))
#define SMALL_HEAP_ALLOCATION_SIZE ((size_t)(16 * getpagesize()))
#define SMALL_BLOCK_SIZE ((size_t)(SMALL_HEAP_ALLOCATION_SIZE / 128))

#define HEAP_TINY  0
#define HEAP_SMALL 1
#define HEAP_LARGE 2


/* Forward Declaretions */
/* ==================== */

typedef struct heap_s heap;
static void *heap_alloc(heap *, size_t size);
static void  heap_free(heap *self, void *memory);
static heap *new_heap(size_t size);
static void  delete_heap(heap *);
static heap *heap_get_begin(void);
static heap *heap_get_end(void);
static heap *heap_get_next(heap *it);
static bool  heap_containes(heap *self, void *memory);

/* ==================== */
/* Forward Declaretions */





/* Malloc & Free */
/* ============= */

void *malloc(size_t size) {
	void *memory = NULL;
	heap *begin = heap_get_begin();
	heap *end = heap_get_end();
	heap *it;

	for (it = begin; it != end; it = heap_get_next(it)) {
		if ((memory = heap_alloc(it, size))) {
			break;
		}
	}

	if (it == NULL) {
		it = new_heap(size);
		memory = heap_alloc(it, size);
	}

	return memory;
}

void free(void *memory) {
	heap *begin = heap_get_begin();
	heap *end = heap_get_end();
	heap *it;
	
	for (it = begin; it != end && !heap_containes(it, memory); it = heap_get_next(it)) { }
	heap_free(it, memory);
}

/* ============= */
/* Malloc & Free */






/* struct block_data */
/* ================= */

typedef unsigned char  byte_t;
typedef struct __attribute__((packed)) block_data_s {
	size_t size : (sizeof(size_t) * 8) - 1;
	size_t occupied : 1;
} block_data_t;
_Static_assert(sizeof(size_t) == sizeof(block_data_t), "is not rigth size");

static inline int  block_data_ctor(block_data_t *self, size_t size);


static inline size_t block_data_get_size(block_data_t *self)                { return self->size; }
static inline void   block_data_set_size(block_data_t *self, size_t size)   { self->size = (size_t)size; }
static inline bool   block_data_is_occupied(block_data_t *self)             { return self->occupied; }
static inline void   block_data_set_occupied(block_data_t *self, bool flag) { self->occupied = flag; }

static inline block_data_t *block_data_get_next(block_data_t *self) {
	return (block_data_t *)((byte_t *)self + block_data_get_size(self) + sizeof(*self));
}
static inline void *block_data_to_memory(block_data_t *self) {
	return (byte_t *)self + sizeof(*self);
}

static inline block_data_t *memory_to_block_data(void *memory) {
	return (block_data_t *)((byte_t *)memory - sizeof(block_data_t));
}

static void block_data_shrink_to_fit(block_data_t *self, size_t size) {
	size_t block_size = block_data_get_size(self);
	
	if (block_size - size <= sizeof(*self) * 2) {
		return;
	}

	block_data_set_size(self, size);
	block_data_t *new = block_data_get_next(self);
	block_data_ctor(new, block_size - size);
}

static void *block_data_alloc(block_data_t *self, size_t size) {
	if (block_data_get_size(self) < size) {
		return NULL;
	}

	block_data_shrink_to_fit(self, size);
	block_data_set_occupied(self, true);

	return block_data_to_memory(self);
}


	/* Ctor & Dtor */
	/* =========== */

static inline int  block_data_ctor(block_data_t *self, size_t size) {
	self->size = size - sizeof(block_data_t);
	self->occupied = false;
	return 0;
}
static inline void   block_data_dtor(block_data_t *self) {
	self->occupied = false;
}

	/* =========== */
	/* Ctor & Dtor */

/* ================= */
/* struct block_data */





/* struct heap */
/* =========== */

typedef struct __attribute__((packed)) heap_data_s {
	size_t size;
	unsigned short type;
} heap_data;

typedef struct __attribute__((packed)) heap_s {
	struct heap_s *prev;
	struct heap_s *next;
	size_t size;
	unsigned short type;
} heap;

static heap *g_heap = NULL;

static inline heap *heap_get_begin(void)    { return g_heap; }
static inline heap *heap_get_end(void)      { return NULL; }
static inline heap *heap_get_next(heap *it) { return it->next; }

static inline block_data_t *heap_get_block_begin(heap *self) {
	return (block_data_t *)((byte_t *)self + sizeof(*self));
}

static inline block_data_t *heap_get_block_end(heap *self) {
	return (block_data_t *)((byte_t *)self + self->size - sizeof(block_data_t));
}

static bool heap_containes(heap *self, void *memory) {
	return memory > (void *)heap_get_block_begin(self) && memory < (void *)heap_get_block_end(self);
}

static heap_data get_heap_data(size_t size) {
	heap_data data;
	if (size <= TINY_BLOCK_SIZE) {
		data.size = TINY_HEAP_ALLOCATION_SIZE;
		data.type = HEAP_TINY;
	} else if (size <= SMALL_BLOCK_SIZE) {
		data.size = SMALL_HEAP_ALLOCATION_SIZE;
		data.type = HEAP_SMALL;
	} else {
		data.type = HEAP_LARGE;
		data.size = size + sizeof(heap) + sizeof(block_data_t) * 2;
	}
	return data;
}

static void heap_try_merge_block(heap *self, block_data_t *block) {
	block_data_t *begin = block_data_get_next(block);
	block_data_t *end   = heap_get_block_end(self);
	block_data_t *it;

	for (it = begin; it != end && !block_data_is_occupied(it); it = block_data_get_next(it)) {
		block_data_set_size(block,
			block_data_get_size(block) + block_data_get_size(it) + sizeof(*it));
	}
}

void *heap_alloc(heap *self, size_t size) {
	if (self->type != get_heap_data(size).type) {
		return NULL;
	}

	block_data_t *begin = heap_get_block_begin(self);
	block_data_t *end   = heap_get_block_end(self);
	block_data_t *it;
	void *memory = NULL;

	for (it = begin; it != end; it = block_data_get_next(it)) {
		if (block_data_is_occupied(it))
			continue;

		heap_try_merge_block(self, it);

		if ((memory = block_data_alloc(it, size))) {
			break;
		}
	}

	return memory;
}

static void delete_heap(heap *obj);

static void heap_free(heap *self, void *memory) {
	block_data_t *first = heap_get_block_begin(self);
	block_data_t *block = memory_to_block_data(memory);

	block_data_set_occupied(block, false);
	heap_try_merge_block(self, block);
	heap_try_merge_block(self, first);

	if (block_data_get_size(first) + sizeof(block_data_t) * 2 + sizeof(*self) == self->size) {
		delete_heap(self);
	}
}



	/* Ctor & Dtor */
	/* =========== */

static void heap_prep(heap *self, heap_data data) {
	self->size = data.size;
	self->type = data.type;
	self->next = g_heap;
	g_heap = self;
	if (self->next != NULL) {
		self->next->prev = self;
	}
}

static int heap_ctor(heap *self, heap_data data) {
	heap_prep(self, data);

	block_data_t *begin = heap_get_block_begin(self);
	block_data_t *end   = heap_get_block_end(self);
	size_t memory_size  = self->size - sizeof(*self) - sizeof(*end);

	/**
	 * @brief init first block
	 * @size: (total size) - sizeof(struct heap)  - sizeof(last block)
	 */
	block_data_ctor(begin, memory_size);

	/**
	 * @brief init last block
	 */
	block_data_ctor(end, sizeof(*end));
	block_data_set_occupied(end, true);
}

static void heap_dtor(heap *self) {
	block_data_dtor(heap_get_block_begin(self));
}

static heap *new_heap(size_t size) {
	heap *obj;
	heap_data data = get_heap_data(size);

	if ((obj = mmap(NULL, data.size, PROT_READ | PROT_WRITE,
			     MAP_PRIVATE | MAP_ANON, -1, 0)) == NULL) {
		return obj;
	}
	heap_ctor(obj, data);
	return obj;
}

static void delete_heap(heap *obj) {
	if (obj->next) {
		obj->next->prev = obj->prev;
	}
	if (obj->prev) {
		obj->prev->next = obj->next;
	}
	if (obj == g_heap) {
		g_heap = obj->next;
	}
	heap_dtor(obj);
	munmap(obj, obj->size);
}

	/* =========== */
	/* Ctor & Dtor */

/* =========== */
/* struct heap */
