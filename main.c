#include "deque.h"
#include "tokenizer.h"
#include "tokens_handler.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - monty language interpreter
 *
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 1 on success, otherwise 1
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		Tokens tokens = tokenize(line);
		static size_t line_number;

		++line_number;

		if (tokens == NULL)
			continue;

		handle_tokens(tokens, line_number);
		free_tokens(tokens);
	}

	free(line);
	fclose(file);
	deque_free();

	return (EXIT_SUCCESS);
}
