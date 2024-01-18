#include "monty.h"

/**
 * handle_tokens - handles tokens
 *
 * @tokens: tokens
 * @line_number: line number
 */

void handle_tokens(Tokens tokens, size_t line_number)
{
	if (tokens == NULL || tokens[0][0] == '#')
		return;

	if (strcmp(tokens[0], "push") == 0)
		instruction_push(tokens, line_number);
	else if (strcmp(tokens[0], "pall") == 0)
		instruction_pall();
	else if (strcmp(tokens[0], "pint") == 0)
		instruction_pint(line_number);
	else if (strcmp(tokens[0], "pop") == 0)
		instruction_pop(line_number);
	else if (strcmp(tokens[0], "swap") == 0)
		instruction_swap(line_number);
	else if (strcmp(tokens[0], "add") == 0)
		instruction_add(line_number);
	else if (strcmp(tokens[0], "nop") == 0)
		instruction_nop();
	else if (strcmp(tokens[0], "sub") == 0)
		instruction_sub(line_number);
	else if (strcmp(tokens[0], "div") == 0)
		instruction_div(line_number);
	else if (strcmp(tokens[0], "mul") == 0)
		instruction_mul(line_number);
	else if (strcmp(tokens[0], "mod") == 0)
		instruction_mod(line_number);
	else if (strcmp(tokens[0], "pchar") == 0)
		instruction_pchar(line_number);
	else if (strcmp(tokens[0], "pstr") == 0)
		instruction_pstr();
	else if (strcmp(tokens[0], "rotl") == 0)
		instruction_rotl();
	else if (strcmp(tokens[0], "rotr") == 0)
		instruction_rotr();
	else if (strcmp(tokens[0], "stack") == 0)
		instruction_stack();
	else if (strcmp(tokens[0], "queue") == 0)
		instruction_queue();
	else
		instruction_unknown(tokens, line_number);
}
