#include "monty.h"

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
	char line[256];

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

	while (fgets(line, sizeof(line), file) != NULL)
	{
		Tokens tokens = tokenize(line);
		static size_t line_number;

		++line_number;
		handle_tokens(tokens, line_number);
		free_tokens(tokens);
	}

	fclose(file);
	deque_free();

	return (EXIT_SUCCESS);
}
