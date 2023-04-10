#include "main.h"

/**
 * create_file - create a file
 * @text_content: A pointer to a string to write to the file
 * @filename: A pointer to the name of the file to be create
 *
 * Return: if the function fails --1, otherwise -1.
 */
int create_file(const char *filename, char *text_content)
{
	int pg, r, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	pg = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	r = write(pg, text_content, len);

	if (pg == -1 || r == -1)
		return (-1);

	close(pg);
	return (1);
}
