#include "main.h"

/**
 * flip_bits - to count the number of bits to change
 * @m: second number
 * @n: first number
 * Return: number of bits to be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int q, count = 0;

	unsigned long int base;
	unsigned long int result = n ^ m;

	for (q = 63; q >= 0; q--)
	{
	base = result >> q;
	if (base & 1)
	count++;
	}
	return (count);
}
