#include "main.h"

/**
 * binary_to_uint - Convert a binary number to an unsigned int.
 * @b: The binary string to convert.
 *
 * Return: The converted number.
 * Return : 0 if there is an invalid character or b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		result = result * 2 + (b[i] - '0');
		i++;
	}

	return (result);
}
