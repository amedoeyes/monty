#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * deque_is_empty - checks if deque is empty
 *
 * Return: true if deque is empty, false otherwise
 */

bool deque_is_empty(void)
{
	return (_deque_get()->size == 0);
}

/**
 * deque_push - adds data to deque
 *
 * @data: data to add
 */

void deque_push(int data)
{
	if (_deque_get()->mode == DEQUE_STACK)
		_deque_push_front(data);
	else
		_deque_push_back(data);
}

/**
 * deque_pop - removes data from deque
 *
 * Return: the data
 */

int deque_pop(void)
{
	return (_deque_pop_front());
}

/**
 * deque_peek - get the data of the top of the deque
 *
 * Return: the data
 */

int deque_peek(void)
{
	return (_deque_get()->head->data);
}

/**
 * deque_set_mode - sets the mode of the deque
 *
 * @mode: DEQUE_STACK or DEQUE_QUEUE
 */

void deque_set_mode(DequeMode mode)
{
	_deque_get()->mode = mode;
}
