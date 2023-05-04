#include "main.h"
/**
 * flip_bits - Function that counts the
 * number of bits to change
 * to get from one number to another
 * @n: The first number
 * @m: The second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{


	int v, base = 0;
	unsigned long int gent;
	unsigned long int dent = n ^ m;

	for (v = 63; v >= 0; v--)
	{
		gent = dent >> v;
		if (gent & 1)
			base++;
	}


	return (base);
}
