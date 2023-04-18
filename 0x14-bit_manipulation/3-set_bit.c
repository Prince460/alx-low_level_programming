#include "main.h"

/**
 * set_bit - To set the bit ata given index
 * @n: pointer to number to be changed
 * @index: index of the bit
 * Return: 1 for success or -1 for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int d;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	d = 1 << index;
	*n = *n | d;
		return (1);
}
