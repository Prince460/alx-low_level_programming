#include "main.h"


/**
 * append_text_to_file - Function that
 * appends text at the end of a file.
 * @filename: The pointer to the name of the file.
 * @text_content: The string that will be
 * added to the end of the file.
 * Return: Once the function fails or filename is NULL - -1.
 *         Once the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{

	int g, k, len = 0;

	if (filename == NULL)

		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	g = open(filename, O_WRONLY | O_APPEND);
	k = write(g, text_content, len);

	if (g == -1 || k == -1)
		return (-1);

	close(g);

	return (1);
}
