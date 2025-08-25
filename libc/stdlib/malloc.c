/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:35:58 by larlena           #+#    #+#             */
/*   Updated: 2025/08/24 00:39:40 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include <stdbool.h>
#include <stddef.h>
#include <sys/mmap.h>

#define TINY_HEAP_ALLOCATION_SIZE ((size_t)(4 * getpagesize()))
#define TINY_BLOCK_SIZE ((size_t)(TINY_HEAP_ALLOCATION_SIZE / 128))
#define SMALL_HEAP_ALLOCATION_SIZE ((size_t)(16 * getpagesize()))
#define SMALL_BLOCK_SIZE ((size_t)(SMALL_HEAP_ALLOCATION_SIZE / 128))

#define HEAP_SHIFT(start) ((void *)start + sizeof_heap())
#define BLOCK_SHIFT(start) ((void *)start + sizeof(block))

#define BLOCK_FREE 0x1
#define BLOCK_OCCUPIED 0x0
#define BLOCK_FLAG_OFFSET 1

#define __HEAP_METADATA_SIZE__ \
	((size_t)(sizeof_heap() + 3 * __BLOCK_METADATA_SIZE__))
#define __MIN_USER_DATA__ \
	((size_t)(0x1 << BLOCK_FLAG_OFFSET))
#define __MIN_BLOCK_SIZE__ \
	((size_t)(__BLOCK_METADATA_SIZE__ + __MIN_USER_DATA__))

# define TINY 0x01
# define SMALL 0x02
# define LARGE 0x04



typedef struct s_block {
	size_t data;
} block;

static inline bool block_is_free(const block *self) {
	return self->data & BLOCK_FREE;
}

static inline void block_set_free(block *self) {
	self->data |= BLOCK_FREE;
}

static inline void block_set_occupied(block *self) {
	self->data &= (__SIZE_MAX__ << 0x1);
}

inline static void block_set_size(block *self, size_t size) {
	self->data = (size & (__SIZE_MAX__ << BLOCK_FLAG_OFFSET)) | (self->data & BLOCK_FREE);
}

inline static size_t block_get_size(const block *self) {
	return self->data & (__SIZE_MAX__ << BLOCK_FLAG_OFFSET);
}

enum direction {
	e_forward,
	e_backward,
};

typedef struct s_block_list {
	block lhs;
	block rhs;
} block_node;

inline static block_node *block_node_next(block_node *self) {
	return (void *)self + block_get_size(&self->rhs);
}

inline static block_node *block_node_prev(block_node *self) {
	return (void *)self - block_get_size(&self->lhs);
}

inline static bool block_node_last(block_node *self, enum direction direction) {
	if (direction == e_forward) {
		return !block_get_size(&self->rhs) && !block_is_free(&self->rhs);
	} else {
		return !block_get_size(&self->lhs) && !block_is_free(&self->lhs);
	}
}

inline static int block_node_init(block_node *self) {
	memset(self, 0, sizeof(*self));
	block_set_occupied(&self->lhs);
	block_set_size(&self->lhs, 0);
	block_set_occupied(&self->rhs);
	block_set_size(&self->rhs, 0);
	return 0;
}

inline static void block_node_deinit(block_node *self) { }

static block_node *block_list_create(void *raw, size_t size) {
	block_node *begin = raw;
	block_node *end = raw + size - sizeof(end);
	size_t free_size = size - sizeof(block_node) * 2;

	block_node_init(begin);
	block_set_free(&begin->rhs);
	block_set_size(&begin->rhs, free_size);

	block_node_init(end);
	block_set_free(&end->lhs);
	block_set_size(&end->lhs, free_size);
	return begin;
}

static void block_node_merge(block_node *first, block_node *second) {
	block_set_size(&first->rhs,
		  block_get_size(&second->lhs)
		+ block_get_size(&second->rhs)
		+ sizeof(*second));

	block_set_size(&block_node_next(first)->lhs, block_get_size(&first->rhs));
}

typedef struct s_heap {
	struct s_heap *prev;
	struct s_heap *next;
	size_t total_size;
	size_t flags;
} heap;

size_t sizeof_heap() { return sizeof(heap); }

heap *g_heap = NULL;

inline static bool block_is_free(const block *);
inline static block *get_free_block(size_t size);
inline static void block_mark_free(block *);
inline static void block_mark_occupied(block *);
inline static block *block_get_next(block *);
inline static block *block_get_prev(block *);
static void free_heap__(heap *heap);
static block *merge_adjacent_free_blocks__(block *block);
static void *get_first_free_block(block_node *node,
				    block_node *(*iterate)(block_node *));

void *malloc(size_t size) {
	block *dst;

	if ((size == 0) || ((dst = get_free_block(size)) == NULL)) {
		return NULL;
	}
	block_mark_occupied(dst);
	dst->next->prev = dst->prev;
	dst->prev->next = dst->next;
	get_current_block_tail(dst)->data = dst->data;
	return BLOCK_SHIFT(dst);
}

void free(void *ptr) {
	block *block = (void *)ptr - sizeof(block);

	if (ptr == NULL) {
		return;
	}
	block_mark_free(&block->data);
	block = merge_adjacent_free_blocks__(block);
	get_current_block_tail(block)->data = block->data;
	block->next = get_first_free_block(block, block_get_next);
	block->prev = get_first_free_block(block, block_get_prev);
	block->prev->next = block;
	block->next->prev = block;
	if (is_meta_block__(block_get_next(block)->data) &&
	    is_meta_block__(block_get_prev(block)->data)) {
		free_heap__((void *)block->prev - sizeof_heap());
	}
}

/*
============================
	SHARED UTILS
============================
*/

inline static bool is_tiny_heap__(unsigned char flag) {
	return flag & TINY;
}

inline static bool is_small_heap__(unsigned char flag) {
	return flag & SMALL;
}

inline static bool is_large_heap__(unsigned char flag) {
	return flag & LARGE;
}

inline static bool is_tiny_block__(size_t size) {
	return size <= TINY_BLOCK_SIZE;
}

inline static bool is_small_block__(size_t size) {
	return size <= SMALL_BLOCK_SIZE;
}

inline static bool is_large_block__(size_t size) {
	return size > SMALL_BLOCK_SIZE;
}

inline static size_t round_size(size_t size) {
	return (size & (__SIZE_MAX__ << BLOCK_FLAG_OFFSET)) +
	       (1 << BLOCK_FLAG_OFFSET);
}

static size_t get_size_of_heap__(size_t block_size, unsigned char block_type) {
	if (is_tiny_heap__(block_type)) {
		return TINY_HEAP_ALLOCATION_SIZE;
	} else if (is_small_heap__(block_type)) {
		return SMALL_HEAP_ALLOCATION_SIZE;
	} else {
		return block_size + __HEAP_METADATA_SIZE__;
	}
}

static unsigned char get_type_of_heap__(size_t block_size) {
	if (is_tiny_block__(block_size)) {
		return TINY;
	} else if (is_small_block__(block_size)) {
		return SMALL;
	} else {
		return LARGE;
	}
}

static void primary_block_init(heap *heap, size_t heap_size) {
	size_t size = heap_size - sizeof_heap();
	block *first = HEAP_SHIFT(heap);
	block *last = (void *)first + size - __BLOCK_METADATA_SIZE__;
	block *block = (void *)first + __BLOCK_METADATA_SIZE__;

	block_init(first, 0);
	first->data = BLOCK_OCCUPIED;
	block_init(last, 0);
	last->data = BLOCK_OCCUPIED;
	block_init(block, ((void *)last - (void *)first) -
				2 * __BLOCK_METADATA_SIZE__);
	first->next = block;
	first->prev = last;
	last->next = first;
	last->prev = block;
	block->next = last;
	block->prev = first;
}

/*
================================
	UTILS FOR MALLOC
================================
*/

static void *heap_init(heap *heap, size_t size, size_t heap_type) {
	heap->total_size = size;
	heap->flags = heap_type;
	heap->next = g_heap;
	g_heap = heap;
	if (heap->next != NULL) {
		heap->next->prev = heap;
	}
	return heap;
}

static void *heap_create(size_t size, size_t heap_type) {
	heap *new_heap;
	size_t heap_size = get_size_of_heap__(size, heap_type);

	if ((new_heap = mmap(NULL, heap_size, PROT_READ | PROT_WRITE,
			     MAP_PRIVATE | MAP_ANON, -1, 0)) == NULL) {
		return new_heap;
	}
	heap_init(new_heap, heap_size, heap_type);
	primary_block_init(new_heap, heap_size);
	return new_heap;
}

static void *find_free_heap__(heap *heap, size_t heap_type) {
	while (heap) {
		if (heap->flags == heap_type) {
			return heap;
		}
		heap = heap->next;
	}
	return heap;
}

static void *find_free_block__(heap *heap, size_t size) {
	block *it = ((block *)HEAP_SHIFT(heap))->next;
	block *buff = it;
	size_t it_size = block_get_size(it);
	size_t buff_size = it_size;

	while (it_size) {
		if (((buff_size > it_size) && (it_size >= size)) &&
		    block_is_free(it)) {
			buff = it;
			buff_size = block_get_size(buff);
		}
		it = it->next;
		it_size = block_get_size(it);
	}
	return block_get_size(buff) < size ? NULL : buff;
}

static void trim_block__(block *block, size_t size) {
	size_t block_size = block_get_size(block);
	block *buff;

	if (block_size - size >= __MIN_BLOCK_SIZE__) {
		buff = (void *)block + size + __BLOCK_METADATA_SIZE__;
		block_init(buff, block_size - size - __BLOCK_METADATA_SIZE__);
		buff->next = block->next;
		buff->prev = block;
		block->next = buff;
		buff->next->prev = buff;
		block_set_size(block, size);
		get_current_block_tail(block)->data = block->data;
	}
}

static block *get_free_block(size_t input_size) {
	heap *heap = g_heap;
	block *block;
	size_t size = round_size(input_size);
	size_t heap_type = get_type_of_heap__(size);

	while (true) {
		if ((heap = find_free_heap__(heap, heap_type)) == NULL) {
			if ((heap = heap_create(size, heap_type)) == NULL) {
				return NULL;
			}
		}
		if ((block = find_free_block__(heap, size)) == NULL) {
			heap = heap->next;
		} else {
			break;
		}
	}
	trim_block__(block, size);
	return block;
}

/*
==============================
	UTILS FOR FREE
==============================
*/

inline static bool block_is_meta(const block *block) { return block->data == 0; }

static void free_heap__(heap *heap) {
	if (heap->next) {
		heap->next->prev = heap->prev;
	}
	if (heap->prev) {
		heap->prev->next = heap->next;
	}
	if (heap == g_heap) {
		g_heap = heap->next;
	}
	munmap(heap, heap->total_size);
}

static void *get_first_free_block(block *block,
				    block *(*iterate)(block *)) {
	block = iterate(block);
	while (block && (!block_is_free(block) &&
			 !block_is_meta(block))) {
		block = iterate(block);
	}
	return block;
}

static block *merge_adjacent_free_blocks__(block *block) {
	block *buff;

	buff = block_get_next(block);
	if (block_is_free(buff)) {
		block_merge(block, buff);
	}
	buff = block_get_prev(block);
	if (block_is_free(buff)) {
		block_merge(buff, block);
		block = buff;
	}
	return block;
}
