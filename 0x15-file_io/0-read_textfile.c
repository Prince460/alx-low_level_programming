#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - read text file print to stdout
 * @letters: number of letters to read
 * @filename: text file that will be read
 * Return: w- actual number of bytes to be read and printed
 * the 0 when function fails or NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t w;
	ssize_t y;
	ssize_t pg;
	char *gent;

	pg = open(filename, O_RDONLY);
	if (pg == -1)
		return (0);
	gent = malloc(sizeof(char) * letters);
	y = read(pg, gent, letters);
	w = write(STDOUT_FILENO, gent, y);
	free(gent);
	close(pg);
	return (w);
}
