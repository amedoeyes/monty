#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
#include <stddef.h>

typedef enum
{
	DEQUE_STACK,
	DEQUE_QUEUE
} DequeMode;

/**
 * struct Deque - deque node
 *
 * @data: integer
 * @prev: pointer to the previous node
 * @next: pointer to the next node
 */

typedef struct DequeNode
{
	int data;
	struct DequeNode *prev;
	struct DequeNode *next;
} DequeNode;

/**
 * struct Deque - deque
 *
 * @head: pointer to head of the deque
 * @tail: pointer to tail of the deque
 * @size: size of the deque
 * @mode: mode of the deque
 */

typedef struct Deque
{
	DequeNode *head;
	DequeNode *tail;
	size_t size;
	DequeMode mode;
} Deque;

/* interface */

bool deque_is_empty(void);
void deque_push(int data);
int deque_pop(void);
int deque_peek(void);
void deque_set_mode(DequeMode mode);
void deque_free(void);

/* implementation */

Deque *_deque_get(void);
DequeNode *_deque_node_init(int data);
void _deque_init_nodes(DequeNode *node);
void _deque_push_front(int data);
void _deque_push_back(int data);
int _deque_pop_front(void);

#endif /* !DEQUE_H */
