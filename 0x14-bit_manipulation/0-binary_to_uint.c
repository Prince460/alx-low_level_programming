#include "main.h"
#include "stddef.h"

/**
 * binary_to_uint - converting a binary
 * number to an unsigned int
 * @b: The Pointer to string of 0 and 1 chars
 *
 * Return: The converted number, or 0 once
 *  there is just one/more chars in string b
 *  or b will be NULL
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int yep = 0, u = 0;

	if (b == NULL)
		return (0);

	while (b[u] != '\0')
	{
		if (b[u] != '0' && b[u] != '1')
			return (0);

		yep = yep << 1;
		if (b[u] == '1')
			yep = yep | 1;
		u++;
	}
	return (yep);
}
