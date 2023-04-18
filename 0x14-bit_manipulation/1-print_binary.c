#include "main.h"

/**
 * print_binary - prints binary representation of a decimal number
 * @n: number to be printed in binary
 */
void print_binary(unsigned long int n)
{
	int g, count = 0;

	unsigned long int base;

	for (g = 63; g >= 0; g--)
	{
	base = n >> g;
	if (base & 1)
	{
	_putchar('1');
	count++;
	}
	else if (count)
	_putchar('0');
	}
		if (!count)
			_putchar('0');
}
