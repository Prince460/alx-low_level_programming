#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Function that read text
 * file and print to STDOUT.
 * @filename: The text file that will be  read
 * @letters: The number of letters that will be read
 * Return: w when actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t kl;
	ssize_t l;
	ssize_t g;
	char *buf;

	kl = open(filename, O_RDONLY);
	if (kl == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	l = read(kl, buf, letters);
	g = write(STDOUT_FILENO, buf, l);

	free(buf);
	close(kl);

	return (g);
}
