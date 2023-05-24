#include "main.h"
/**
 * _strtok - this fuction tokenizes string into smaller
 * parts based on delimiters
 * @str:string to be tokenized
 * @delimiters: delimiter characters
 *
 * Return: Pointer to the next token in the string, NULL on error
 */

char *_strtok(char *str, const char *delimiters)
{
	static char *nextToken;
	char *tokenStart;
	char *tokenEnd;

	if (str != NULL)
		nextToken = str;

	if (nextToken == NULL || *nextToken == '\0')
		return (NULL);

	tokenStart = nextToken;
	tokenEnd = strpbrk(nextToken, delimiters);

	if (tokenEnd != NULL)
	{
		*tokenEnd = '\0';
		nextToken = tokenEnd + 1;
	}
	else
	{
		nextToken = NULL;
	}

	return (tokenStart);
}
/**
 * _strncpy - this fuction copys a string with a specified maximum length
 * @destination: points to the destination string
 * @source: points to the source string
 * @num: maximum number of characters to be copied
 * Return: start pointer
 */

char *_strncpy(char *destination, const char *source, size_t num)
{
	char *start = destination;

	while (num > 0 && *source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
		num--;
	}

	while (num > 0)
	{
		*destination = '\0';
		destination++;
		num--;
	}

	return (start);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * @n: maximum number of characters to concatenate
 *
 * Return: pointer to the resulting string
 */
char *_strcat(char *dest, const char *src, size_t n)
{
	size_t dest_len = strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + i] = '\0';

	return (dest);
}
