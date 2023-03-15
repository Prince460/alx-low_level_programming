#include "main.h"
#include <stdio.h>
/**
 * main - Aprogram that prints the number of arguement you passed into it
 * @argc: arguement count
 * @argv: arguement vector
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	if (argv[0])
		printf("%d\n", argc - 1);
	return (0);
}
