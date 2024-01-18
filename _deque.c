#include "monty.h"

static Deque *deque;

/**
 * _init_deque - initializes the deque
 *
 * Return: the deque
 */

static Deque *_deque_init(void)
{
	deque = malloc(sizeof(Deque));

	if (deque == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(1);
	}

	deque->size = 0;
	deque->head = NULL;
	deque->tail = NULL;
	deque->mode = DEQUE_STACK;

	return (deque);
}

/**
 * _get_deque - gets the deque
 *
 * Return: the deque
 */

Deque *_deque_get(void)
{
	if (deque == NULL)
		return (_deque_init());

	return (deque);
}

/**
 * _deque_node_init - initializes a deque node
 *
 * @data: the data to be stored in the node
 *
 * Return: a deque node
 */

DequeNode *_deque_node_init(int data)
{
	DequeNode *node = malloc(sizeof(Deque));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed.\n");
		exit(EXIT_FAILURE);
	}

	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}
