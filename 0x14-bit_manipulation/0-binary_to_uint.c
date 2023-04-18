#include "main.h"

/**
 * binary_to_unit - convert binary number to unsigned int
 * @b: string to contain the binary number
 * Return: converted number
 */
unsigned int binary_to_unit(const char *b)
{
	int v;

	unsigned int x;
	
	x = 0;

	if (!b)
		return (0);
	for (v = 0; b[v]; v++)
	{
	if (b[v] < '0' || b[v] > '1')
		return (0);
	x  = 2 * x + (b[v] - '0');
	}
		return (x);
}
