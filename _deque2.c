#include "monty.h"

/**
 * _deque_init_nodes - initializes deque nodes
 *
 * @node: pointer to deque node
 */

void _deque_init_nodes(DequeNode *node)
{
	Deque *deque = _deque_get();

	deque->head = node;
	deque->tail = node;
	++deque->size;
}

/**
 * _deque_push_front - adds data to the front of the deque
 *
 * @data: data to add
 */

void _deque_push_front(int data)
{
	Deque *deque = _deque_get();
	DequeNode *new_node = _deque_node_init(data);

	if (deque_is_empty())
	{
		_deque_init_nodes(new_node);
		return;
	}

	new_node->next = deque->head;
	deque->head->prev = new_node;
	deque->head = new_node;
	++deque->size;
}

/**
 * _deque_push_back - adds data to the back of the deque
 *
 * @data: data to add
 */

void _deque_push_back(int data)
{
	Deque *deque = _deque_get();
	DequeNode *new_node = _deque_node_init(data);

	if (deque_is_empty())
	{
		_deque_init_nodes(new_node);
		return;
	}

	new_node->prev = deque->tail;
	deque->tail->next = new_node;
	deque->tail = new_node;
	++deque->size;
}

/**
 * _deque_pop_front - removes data from the front of the deque
 *
 * Return: the data
 */

int _deque_pop_front(void)
{
	Deque *deque = _deque_get();
	int data = 0;
	DequeNode *temp = NULL;

	if (deque_is_empty())
	{
		fprintf(stderr, "Error: deque is empty.\n");
		exit(EXIT_FAILURE);
	}

	data = deque->head->data;
	temp = deque->head;

	deque->head = deque->head->next;
	if (deque->head != NULL)
		deque->head->prev = NULL;
	else
		deque->tail = NULL;

	--deque->size;

	free(temp);
	return (data);
}

/**
 * _deque_pop_back - removes data from the back of the deque
 *
 * Return: the data
 */

int _deque_pop_back(void)
{
	Deque *deque = _deque_get();
	int data = 0;
	DequeNode *temp = NULL;

	if (deque_is_empty())
	{
		fprintf(stderr, "Error: deque is empty.\n");
		exit(EXIT_FAILURE);
	}

	data = deque->tail->data;
	temp = deque->tail;

	deque->tail = deque->tail->prev;
	if (deque->tail != NULL)
		deque->tail->next = NULL;
	else
		deque->head = NULL;

	--deque->size;

	free(temp);
	return (data);
}
