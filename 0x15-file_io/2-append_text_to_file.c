#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 * @text_content: the string to be added to the end of file
 * @filename: A pointer to the name of the file
 * Return: --1 in case the function fails or filename is NULL
 * if the file does not exist the user lacks write permission --1
 * otherwise -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int g, r, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	g = open(filename, O_WRONLY | O_APPEND);
	r = write(g, text_content, len);

	if (g == -1 || r == -1)
	return (-1);
	close(g);
	return (1);
}
