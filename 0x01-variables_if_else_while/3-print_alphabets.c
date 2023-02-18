#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that print alphabet in lowercase, and then uppercase
 *
 * Return: Always 0
 */

int main(void)
{
	char low;

	for (low = 'a'; low <= 'z'; low++)
		putchar(low);
	for (low = 'A'; low <= 'Z'; low++)
		putchar(low);
	putchar('\n');

	return (0);
}
