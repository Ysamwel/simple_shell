#include "main.h"

/**
 * cap_string - Capitalizes the first letter of each word in a string.
 * @s: The string to capitalize.
 *
 * Return: Pointer to the resulting string.
 */
char *cap_string(char *s)
{
	int i = 0;
	int capitalize = 1;
	char separators[] = " \t\n,;.!?\"(){}";

	while (s[i] != '\0')
	{
		if (capitalize && (s[i] >= 'a' && s[i] <= 'z'))
		{
			s[i] = s[i] - 'a' + 'A';
		}

		capitalize = 0;
		if (_strchr(separators, s[i]) != NULL)
		{
			capitalize = 1;
		}
		i++;
	}
	return (s);
}

/**
 * _strspn - Calculates the length of a prefix substring.
 * @s: The string to check.
 * @accept: The string containing the characters to match.
 *
 * Return: The number of bytes in the initial segment of s
 *         consisting only of bytes from accept.
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
 * set_string - Sets the value of a pointer to a char.
 * @s: Pointer to change.
 * @to: String to set the pointer to.
 */
void set_string(char **s, char *to)
{
	*s = to;
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string.
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
 * _strpbrk - Searches a string for any of a set of bytes.
 * @str: The string to search.
 * @delimiters: The characters to search for.
 *
 * Return: Pointer to the first occurrence of any character from delimiters
 *         in the string str, or NULL if no match is found.
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

