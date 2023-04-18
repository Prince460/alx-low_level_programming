#include "main.h"

/**
 * get_bit - returning the value of the bit
 * @n: number that will be searched
 * @index: index of the bit
 * Return: The value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int div_res;

	if (index > 63)
		return (-1);
	div_res = (n >> index) & 1;
	return (div_res);
}
