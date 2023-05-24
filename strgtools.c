#include "main.h"
/**
 * _strtok - tokenizes command
 * @str: the string
 * @delimiters: tokens splittted
 * Return: Token
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
	tokenEnd = _strpbrk(nextToken, delimiters);
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
 * _strncpy - Copies a specified number strings
 * @destination: Pointer to the destination string.
 * @source: Pointer to the source string.
 * @num: Maximum number of characters to be copied.
 *
 * Return: Pointer to the destination string.
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
 * _strcat - Concatenates two strings, limiting the number of characters.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Maximum number of characters to concatenate.
 *
 * Return: Pointer to the resulting string.
 */
char *_strcat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * s_strcpy - Copies a string from source to destination.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the destination string.
 */
char *s_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return  (dest);
}

