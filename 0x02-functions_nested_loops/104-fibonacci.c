#include <stdio.h>
/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int a = 1, b = 2, c, i, n;

	printf("%d, %d, ", a, b);

	for (i = 3, n = 98; i <= n; i++)
	{
		c = a + b;
		printf("%d, ", c);
		a = b;
		b = c;
	}
	printf("%d\n", a + b);
	return (0);
}
