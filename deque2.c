#include "monty.h"

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
 * deque_is_empty - checks if deque is empty
 *
 * Return: true if deque is empty, false otherwise
 */

bool deque_is_empty(void)
{
	return (_deque_get()->size == 0);
}

/**
 * deque_get_size - returns the size of the deque
 *
 * Return: the size
 */

size_t deque_get_size(void)
{
	return (_deque_get()->size);
}

/**
 * deque_get_mode - returns the mode of the deque
 *
 * Return: the mode
 */

DequeMode deque_get_mode(void)
{
	return (_deque_get()->mode);
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
