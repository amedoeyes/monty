#include "monty.h"

/**
 * instruction_rotr - rotates the deque to the bottom
 */

void instruction_rotr(void)
{
	int temp;

	if (deque_is_empty())
		return;

	temp = deque_pop_back();
	deque_push_front(temp);
}

/**
 * instruction_stack - sets the deque mode to stack
 */

void instruction_stack(void)
{
	deque_set_mode(DEQUE_STACK);
}

/**
 * instruction_queue - sets the deque mode to queue
 */

void instruction_queue(void)
{
	deque_set_mode(DEQUE_QUEUE);
}
