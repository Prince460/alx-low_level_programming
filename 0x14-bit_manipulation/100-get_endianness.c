#include "main.h"

/**
 * get_endianness - checks if machine is small or large endian
 * Return: 0 if large of 1 if small
 */
int get_endianness(void)
{
	unsigned int z = 1;

	char *c = (char *) &z;

	return (*c);
}
