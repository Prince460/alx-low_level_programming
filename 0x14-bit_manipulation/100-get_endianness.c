#include "main.h"
/**
 * get_endianness - Set to check if a machine
 * is little or big endian
 * Return: 0 once big, 1 once little
 */
int get_endianness(void)
{
	unsigned int j = 1;
	char *g = (char *) &j;

	return (*g);
}
