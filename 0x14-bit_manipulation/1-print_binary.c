#include "main.h"
/**
 * print_binary - Function that prints the binary
 * equivalent of a decimal number
 * @n: number that will be printed in binary
 */
void print_binary(unsigned long int n)
{
	int v, base = 0;
	unsigned long int gent;

	for (v = 63; v >= 0; v--)
	{
		gent = n >> v;

		if (gent & 1)
		{
			_putchar('1');
			base++;
		}
		else if (base)
			_putchar('0');
	}
	if (!base)
		_putchar('0');
}
