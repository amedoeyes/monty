#include "monty.h"

#define DELIM " \t\n"

/**
 * token_count - counts the tokens in a string
 *
 * @str: string to count tokens from
 *
 * Return: token count
 */

static size_t token_count(const char *str)
{
	size_t count = 0;
	Token token = NULL;
	char *copy = NULL;

	if (str == NULL)
		return (0);

	copy = _strdup(str);
	if (copy == NULL)
	{
		fprintf(stderr, "Error: strdup failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, DELIM);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, DELIM);
	}

	free(copy);
	return (count);
}

/**
 * tokenize - tokenizes an instruction string
 *
 * @str: string to tokenize
 *
 * Return: an array of instruction tokens
 */

char **tokenize(const char *str)
{
	Token token = NULL;
	Tokens tokens = NULL;
	char *copy = NULL;
	size_t count = token_count(str);
	size_t i;

	if (str == NULL || count == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count + 1));
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	copy = _strdup(str);
	if (copy == NULL)
	{
		fprintf(stderr, "Error: strdup failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, DELIM);
	for (i = 0; i < count; i++)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			fprintf(stderr, "Error: strdup failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, DELIM);
	}
	tokens[count] = NULL;

	free(copy);
	return (tokens);
}

/**
 * free_tokens - frees tokens
 *
 * @tokens: tokens to free
 */

void free_tokens(Tokens tokens)
{
	size_t i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);

	free(tokens);
}
