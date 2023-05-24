#include "main.h"
/**
 * _strspn - calculates the length of a prefix substring
 * @s: string to check
 * @accept: string containing the characters to match
 *
 * Return: the number of bytes in the initial segment of s
 * consisting only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				break;
			}
		}

		if (accept[j] == '\0')
		{
			return (count);
		}
	}

	return (count);
}

/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to change
 * @to: string to set the pointer to
 */
void set_string(char **s, char *to)
{
	*s = to;
}
/**
 * _strdup - this function duplicates a string
 * @str: string
 * Return: duplicate
 */

char *_strdup(const char *str)
{
	size_t i;
	size_t length = 0;
	char *duplicate;

	if (str == NULL)
		return (NULL);


	while (str[length] != '\0')
		length++;

	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}


/**
 * _strpbrk - it locates first occurrence in a string of
 * any of the specified delimiters.
 * @str: string to search.
 * @delimiters: delimiters to search for.
 *
 * Return: pointer to the first occurrence of a character
 * or NULL if no match is found.
 */

char *_strpbrk(const char *str, const char *delimiters)
{
	while (*str != '\0')
	{
		const char *delimiter = delimiters;

		while (*delimiter != '\0')
		{
			if (*str == *delimiter)
				return ((char *)str);
			delimiter++;
		}
		str++;
	}

	return (NULL);
}
