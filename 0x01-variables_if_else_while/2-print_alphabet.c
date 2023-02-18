#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - program that print the alphabet in lowercase
 *
 * Return: 0
 */
int main(void)
{
	char low;

	for (low = 'a'; low <= 'z'; low++)
	{
		putchar(low);
	}
	putchar('\n');

	return (0);
}
