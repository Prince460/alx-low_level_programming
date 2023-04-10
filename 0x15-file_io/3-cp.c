#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int pg);

/**
 * create_buffer - Allocates 1024 bytes for buffer
 * @file: Name of the file buffer is storing char for
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
 * close_file - close file descriptor
 * @pg: file descriptor to be closed.
 */
void close_file(int pg)
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
	int from, to, v;
	char *buffer;

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "usage: cp file_from file_to\n");
	exit(97);
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	v = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {

	if (from == -1 || v == -1)
	{
	dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]);
	free(buffer);
	exit(99);
	}
	v = read(from, buffer, 1024);
	to = open(argv[2], O_WRONLY | O_APPEND);

	} while (v > 0);
	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
