#include "main.h"
/**
 * processLine - Updates the line buffer with the given input
 * @linptr: Pointer to the line buffer
 * @g: Pointer to the size of the line buffer
 * @buff: Input buffer to copy from
 * @l: Length of the input buffer
 *
 * This function updates the line buffer with the given input, reallocating
 * memory if necessary to accommodate the input. It uses the linptr and g
 * parameters to manage the line buffer and ensure sufficient memory.
 */
void processLine(char **linptr, size_t *g, char *buff, size_t l)
{
	char *newptr;

	if (*linptr == NULL || *g < l)
	{
		if (l > BUFSIZE)
			*g = l;
		else
			*g = BUFSIZE;

		newptr = _realloc(*linptr, *g);

		if (newptr == NULL)
		{
			perror("realloc");
			free(linptr);
			exit(1);
		}
		*linptr = newptr;
	}

	s_strcpy(*linptr, buff);
}
/**
 * custom_getLine - Reads a line from a file stream
 * @linptr: Pointer to the line buffer
 * @g: Pointer to the size of the line buffer
 * @stream: File stream to read from
 * Return: Number of characters read
 */
ssize_t custom_getLine(char **linptr, size_t *g, FILE *stream)
{
	ssize_t retval = -1;
	static int input;
	char *buff, c;

	if (input != 0)
		return (-1);
	fflush(stream);
	input = 0;
	buff = malloc(sizeof(char) * BUFSIZE);
	if (buff == NULL)
		return (-1);
	while ((c = getc(stream)) != '\n')
	{
		if (c == EOF && input == 0)
		{
			free(buff);
			return (-1);
		}
		if (input >= BUFSIZE - 1)
		{
			size_t newSize = (*g > BUFSIZE) ? *g : BUFSIZE;
			char *newBuff = realloc(buff, newSize * 2);

			if (newBuff == NULL)
			{
				free(buff);
				return (-1);
			}
			*g = newSize * 2;
			buff = newBuff;
		}
		buff[input] = c;
		input++;
	}
	buff[input] = '\0';
	processLine(linptr, g, buff, input);
	retval = input;
	input = 0;
	free(buff);
	return (retval);
}
