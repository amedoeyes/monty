#include "monty.h"

/**
 * instruction_mul - multiplies the top two elements of the deque
 *
 * @line_number: line_number
 */

void instruction_mul(size_t line_number)
{
	int temp1;
	int temp2;

	if (deque_get_size() < 2)
	{
		fprintf(stderr, "L%lu: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp1 = deque_pop_front();
	temp2 = deque_pop_front();

	deque_push_front(temp2 * temp1);
}

/**
 * instruction_mod - modules the top two elements of the deque
 *
 * @line_number: line_number
 */

void instruction_mod(size_t line_number)
{
	int temp1;
	int temp2;

	if (deque_get_size() < 2)
	{
		fprintf(stderr, "L%lu: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (deque_peek() == 0)
	{
		fprintf(stderr, "L%lu: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp1 = deque_pop_front();
	temp2 = deque_pop_front();

	deque_push_front(temp2 % temp1);
}

/**
 * instruction_pchar - prints the char at the top of the deque
 *
 * @line_number: line_number
 */

void instruction_pchar(size_t line_number)
{
	char ch;

	if (deque_is_empty())
	{
		fprintf(stderr, "L%lu: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ch = deque_peek();

	if (!is_ascii(ch))
	{
		fprintf(stderr, "L%lu: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ch);
}

/**
 * instruction_pstr - prints the string at the top of the deque followed by a
 * new line
 */

void instruction_pstr(void)
{
	char *str;
	size_t len = 0;

	str = malloc(sizeof(char) * deque_get_size() + 1);
	if (str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (!deque_is_empty() && is_ascii(deque_peek()) && deque_peek() != 0)
	{
		str[len++] = deque_pop_front();
	}
	str[len] = '\0';

	printf("%s\n", str);

	for (; len > 0; --len)
	{
		deque_push(str[len - 1]);
	}

	free(str);
}

/**
 * instruction_rotl - rotates the deque to the top
 */

void instruction_rotl(void)
{
	int temp;

	if (deque_is_empty())
		return;

	temp = deque_pop_front();
	deque_push_back(temp);
}
