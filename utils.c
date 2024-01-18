#include "monty.h"

/**
 * is_integer - checks if a string is an integer
 *
 * @str: string to check
 *
 * Return: true if integer, false otherwise
 */

bool is_integer(const char *str)
{
	size_t i = 0;

	if (str[i] == '-')
		++i;

	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (false);

		++i;
	}

	return (true);
}

/**
 * is_ascii - checks if a char is an ASCII char
 *
 * @c: character to check
 *
 * Return: true if ASCII, false otherwise
 */

bool is_ascii(char c)
{
	return ((unsigned char)c <= 127);
}

/**
 * _strdup - duplicate a string
 *
 * @str: string to duplicate
 *
 * Return: pointer to duplicate or NULL
 */

char *_strdup(const char *str)
{
	char *dup;

	if (str == NULL)
		return (NULL);

	dup = (char *)malloc(strlen(str) + 1);

	if (dup == NULL)
		return (NULL);

	strcpy(dup, str);

	return (dup);
}
