#include "main.h"

/**
 * read_textfile - Reads and prints a text file to the standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print.
 *         0 if the file can't be opened, read, or if filename is NULL.
 *         0 if write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file_descriptor, read_chars, write_chars;
	char *buffer;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	read_chars = read(file_descriptor, buffer, letters);
	if (read_chars == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	write_chars = write(STDOUT_FILENO, buffer, read_chars);

	free(buffer);
	close(file_descriptor);

	if (write_chars == -1 || write_chars != read_chars)
		return (0);

	return (read_chars);
}
