#include "monty.h"

/**
 * deque_print - prints the deque
 */

void deque_print(void)
{
	DequeNode *head = _deque_get()->head;

	while (head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

/**
 * deque_free - frees the deque
 */

void deque_free(void)
{
	while (!deque_is_empty())
		deque_pop_front();

	free(_deque_get());
}
