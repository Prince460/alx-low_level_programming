#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that print all single digit number of base 10
 *
 * Return: Always 0
 */

int main(void)
{
	int d;

	for (d = '0'; d <= '9'; d++)
		putchar(d);
	putchar('\n');

	return (0);
}
