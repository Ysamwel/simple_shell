#include "main.h"
void get_line(char **linptr, size_t *g, char *buff, size_t l)
{

	if (*linptr == NULL)
	{
		if  (l > BUFSIZE)
			*g = l;

		else
			*g = BUFSIZE;
		*linptr = buff;
	}
	else if (*g < l)
	{
		if (l > BUFSIZE)
			*g = l;
		else
			*g = BUFSIZE;
		*linptr = buff;
	}
	else
	{
		_strcpy(*linptr, buff);
		free(buff);
	}
}
ssize_t get_line(char **linptr, size_t *g, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buff;
	char j = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buff = malloc(sizeof(char) * BUFSIZE);
	if (buff == 0)
		return (-1);
	while (j != '\n')
	{
		i = read(STDIN_FILENO, &j, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buff);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buff = _realloc(buff, input, input + 1);
		buff[input] = j;
		input++;
	}
	buff[input] = '\0';
	get_line(linptr, g, buff, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
