#include "utils.h"

#include <ctype.h>
#include <stdlib.h>

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
