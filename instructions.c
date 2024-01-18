#include "monty.h"

/**
 * instruction_unknown - handles unknown instructions
 *
 * @tokens: tokens
 * @line_number: line_number
 */

void instruction_unknown(Tokens tokens, size_t line_number)
{
	fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, tokens[0]);
	exit(EXIT_FAILURE);
}

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
		fprintf(stderr, "L%lu: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	deque_push(atoi(tokens[1]));
}

/**
 * instruction_pall - prints the deque
 */

void instruction_pall(void)
{
	deque_print();
}

/**
 * instruction_pint - prints the top of the deque
 *
 * @line_number: line_number
 */

void instruction_pint(size_t line_number)
{
	if (deque_is_empty())
	{
		fprintf(stderr, "L%lu: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", deque_peek());
}

/**
 * instruction_pop - pops the top of the deque
 *
 * @line_number: line_number
 */

void instruction_pop(size_t line_number)
{
	if (deque_is_empty())
	{
		fprintf(stderr, "L%lu: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	deque_pop_front();
}
