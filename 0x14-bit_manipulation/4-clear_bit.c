#include "main.h"

/**
 * clear_bit - setting the value of a bit to 0
 * @index: index to be cleared
 * @n: pointer to the number to be chnaged
 * Return: 1 for success or -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int z;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	z = ~(1 << index);
	*n = *n & z;
		return (1);
}
