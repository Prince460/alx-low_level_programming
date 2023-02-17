#include <stdio.h>
/**
 * main - print out sizes of data type in c
 *
 * Return: 0
*/
int main(void)
{
	char i;
	int b;
	long int c;
	long long int d;
	float f;

	printf("Size of an char: %lu byte(s)\n", (unsigned long)sizeof(i));
	printf("Size of a int: %lu byte(s)\n", (unsigned long)sizeof(b));
	printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(c));
	printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(d));
	printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(f));
	return (0);
}
