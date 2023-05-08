#include "main.h"


/**
 * create_file - Function that will creates a file.
 * @filename: The pointer to the name of the file to create.
 * @text_content: The pointer to a string
 * that will write to the file.
 *
 * Return: Once the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int kl, g, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{

		for (len = 0; text_content[len];)
			len++;
	}

	kl = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	g = write(kl, text_content, len);

	if (kl == -1 || g == -1)

		return (-1);

	close(kl);

	return (1);
}
