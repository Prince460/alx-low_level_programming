#include "main.h"
#include <stdio.h>
#include <stdlib.h>


char *create_buffer(char *file);
void close_file(int kl);

/**
 * create_buffer - Function that allocates
 * 1024 bytes for a buffer.
 * @file: Name of the file buffer is storing chars for.
 * Return: The pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{

	char *buffer;

	buffer = malloc(sizeof(char) * 1024);


	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Function that loses file descriptor.
 * @kl: File descriptor to be closed.
 */

void close_file(int kl)
{
	int g;

	g = close(kl);

	if (g == -1)
	{

		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", kl);
		exit(100);
	}
}

/**
 * main - Function that copies the
 * contents of a file to another file.
 * @argc: The number of arguments that
 * will be supplied to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 *
 * Description: Once the argument count is incorrect - exit code 97.
 * Once file_from does not exist or cannot be read - exit code 98.
 * Once file_to cannot be created or written to - exit code 99.
 * Once file_to or file_from cannot be closed - exit code 100.
 */

int main(int argc, char *argv[])
{
	int base, back, u, e;
	char *buffer;

	if (argc != 3)
	{

		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	base = open(argv[1], O_RDONLY);
	u = read(base, buffer, 1024);
	back = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);


	do {
		if (base == -1 || u == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		e = write(back, buffer, u);

		if (back == -1 || e == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		u = read(base, buffer, 1024);
		back = open(argv[2], O_WRONLY | O_APPEND);

	} while (u > 0);

	free(buffer);
	close_file(base);
	close_file(back);

	return (0);
}
