#include "main.h"
/**
 * print_last_digit - print last digit of a number
 * @n: Number to be printed
 * Return: The value of the last digit of number
 */

int print_last_digit(int n)
{
	if (n < 0)
	n *= -1;

	_putchar('0' + (n % 10));

	return (n % 10);
}
