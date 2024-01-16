#include "instructions.h"
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_tokens - handles tokens
 *
 * @tokens: tokens
 * @line_number: line number
 */

void handle_tokens(Tokens tokens, size_t line_number)
{
	Token op = tokens[0];

	if (strcmp(op, "push") == 0)
		instruction_push(tokens, line_number);
	else if (strcmp(op, "pall") == 0)
		instruction_pall();
	else if (strcmp(op, "pint") == 0)
		instruction_pint(line_number);
	else if (strcmp(op, "#") == 0)
	{
		return; /* you have to have braces here because betty is dumb... */
	}
	else
	{
		fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}
