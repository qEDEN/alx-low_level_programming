#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file.
 * @text_content: A NULL-terminated string to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, text_length;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(file_descriptor);
		return (1);
	}

	for (text_length = 0; text_content[text_length]; text_length++)
		continue;

	write_result = write(file_descriptor, text_content, text_length);

	if (write_result == -1 || write_result != text_length)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);
	return (1);
}
