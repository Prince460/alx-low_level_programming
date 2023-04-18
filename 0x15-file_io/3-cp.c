#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_pg(int pg);

/**
 * create_buffer - To allocates 1024 bytes for buffer
 * @pg: Name of the file buffer is storing char for
 * Return: A pointer to the new allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_pg - The closure for file descriptor
 * @pg: file descriptor that will be closed.
 */
void close_pg(int pg)
{
	int g;

	g = close(pg);

	if (g == -1)
	{
	dprintf(STDERR_FILENO, "Error: can't close pg %d\n", pg);
	exit(100);
	}
}
/**
 * main - copy the contents of the file to another
 * @argc: Number of arguments supplied to the program
 * @argv: Array of pointer to arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, lo, xc;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	lo = read(file_from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (file_from == -1 || lo == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		xc = write(file_to, buffer, lo);
		if (file_to == -1 || xc == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		lo = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (lo > 0);
	free(buffer);
	close_pg(file_from);
	close_pg(file_to);
	return (0);
}
