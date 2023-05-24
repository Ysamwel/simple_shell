#include "main.h"

/**
 * my_puts - Prints a string to stdout
 * @str: String to be printed
 * @append_newline: Boolean indicating whether to append a newline character
 * Return: Number of bytes written
 */
int my_puts(const char *str, bool append_newline)
{
	int bytes = 0;

	while (*str != '\0')
	{
		if (write(STDOUT_FILENO, str, 1) == -1)
			return (-1);

		str++;
		bytes++;
	}

	if (append_newline)
	{
		if (write(STDOUT_FILENO, "\n", 1) == -1)
			return (-1);

		bytes++;
	}

	return (bytes);
}
