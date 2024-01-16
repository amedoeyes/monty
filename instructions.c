#include "instructions.h"
#include "deque.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * instruction_push - pushs an integer to the deque
 *
 * @tokens: tokens
 * @line_number: line number
 */

void instruction_push(Tokens tokens, size_t line_number)
{
	if (tokens[1] == NULL || !is_integer(tokens[1]))
	{
		fprintf(stderr, "L%lu: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	deque_push(atoi(tokens[1]));
}

/**
 * instruction_pall - prints the deque
 */

void instruction_pall(void)
{
	while (!deque_is_empty())
	{
		printf("%d\n", deque_pop());
	}
}

/**
 * instruction_pint - prints the the top of the deque
 *
 * @line_number: line_number
 */

void instruction_pint(size_t line_number)
{
	if (deque_is_empty())
	{
		fprintf(stderr, "L%lu: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", deque_peek());
}
