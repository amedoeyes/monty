#include "monty.h"

/**
 * deque_push_front - adds data to the front of the deque
 *
 * @data: data to add
 */

void deque_push_front(int data)
{
	_deque_push_front(data);
}

/**
 * deque_push_back - adds data to the back of the deque
 *
 * @data: data to add
 */

void deque_push_back(int data)
{
	_deque_push_back(data);
}

/**
 * deque_push - adds data to deque based on mode
 *
 * @data: data to add
 */

void deque_push(int data)
{
	if (deque_get_mode() == DEQUE_STACK)
		deque_push_front(data);
	else
		deque_push_back(data);
}

/**
 * deque_pop_front - removes data from the front of the deque
 *
 * Return: the data
 */

int deque_pop_front(void)
{
	return (_deque_pop_front());
}

/**
 * deque_pop_back - removes data from the back of the deque
 *
 * Return: the data
 */

int deque_pop_back(void)
{
	return (_deque_pop_back());
}
