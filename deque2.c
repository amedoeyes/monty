#include "deque.h"
#include <stdlib.h>

/**
 * deque_free - frees the deque
 */

void deque_free(void)
{
	while (!deque_is_empty())
		deque_pop();

	free(_deque_get());
}
