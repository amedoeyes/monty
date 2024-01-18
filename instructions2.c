#include "monty.h"

/**
 * instruction_swap - swaps the top two elements of the deque
 *
 * @line_number: line number
 */

void instruction_swap(size_t line_number)
{
	int temp1;
	int temp2;

	if (deque_get_size() < 2)
	{
		fprintf(stderr, "L%lu: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp1 = deque_pop_front();
	temp2 = deque_pop_front();

	deque_push(temp1);
	deque_push(temp2);
}

/**
 * instruction_add - adds the top two elements of the deque
 *
 * @line_number: line_number
 */

void instruction_add(size_t line_number)
{
	int temp1;
	int temp2;

	if (deque_get_size() < 2)
	{
		fprintf(stderr, "L%lu: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp1 = deque_pop_front();
	temp2 = deque_pop_front();

	deque_push_front(temp2 + temp1);
}

/**
 * instruction_nop - does nothing
 */

void instruction_nop(void)
{
	/* do nothing */
}

/**
 * instruction_sub - subtracts the top two elements of the deque
 *
 * @line_number: line_number
 */

void instruction_sub(size_t line_number)
{
	int temp1;
	int temp2;

	if (deque_get_size() < 2)
	{
		fprintf(stderr, "L%lu: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp1 = deque_pop_front();
	temp2 = deque_pop_front();

	deque_push_front(temp2 - temp1);
}

/**
 * instruction_div - divides the top two elements of the deque
 *
 * @line_number: line_number
 */

void instruction_div(size_t line_number)
{
	int temp1;
	int temp2;

	if (deque_get_size() < 2)
	{
		fprintf(stderr, "L%lu: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (deque_peek() == 0)
	{
		fprintf(stderr, "L%lu: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp1 = deque_pop_front();
	temp2 = deque_pop_front();

	deque_push_front(temp2 / temp1);
}
