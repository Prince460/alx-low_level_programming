#include "main.h"

/**
 * print_times_table - prints the times table
 * @n: integer for which the times table will be printed
 *
 * Description: prints the time table
 *
 * Return: void
*/

void print_times_table(int n)
{
	int row, column, result;

	if (n >= 0 && n <= 15)
		for (row = 0; row <= n; row++)
		{
			for (column = 0; column <= n; column++)
			{
				result = row * column;

				if (column == 0)
					_putchar('0');
				else if (result < 10)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
					_putchar(result % 10 + '0');
				}
				else if (result >= 10 && result < 100)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar((result / 10) % 10 + '0');
					_putchar(result % 10 + '0');
				}
				else if (result > 99 && result < 1000)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(result / 100 + '0');
					_putchar((result / 10) % 10 + '0');
					_putchar(result % 10 + '0');
				}
			}
			_putchar('\n');
		}
}
