#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the strin
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++);

	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strchr -  locates a character in a string
 * @s: string
 * @c: target character
 *
 * Return: pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return s;
		}
		s++;
	}
	if (*s == c)
	{
		return s;
	}
	return (NULL);
}

/**
 * rev_string - reverses a string
 * @s: the string to reverse
 */
void rev_string(char *s)
{
	int len = _strlen(s);
	int i, j;
	char temp;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}


/**
 * string_toupper - converts all lowercase characters in a string to uppercase
 * @s: the string to convert
 *
 * Return: pointer to the resulting string
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 'a' + 'A';
		}
		i++;
	}

	return (s);
}

/**
 * cap_string - capitalizes the first letter of each word in a string
 * @s: the string to capitalize
 *
 * Return: pointer to the resulting string
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
			return count;
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
		return NULL;


	while (str[length] != '\0')
		length++;

	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return NULL;

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}


/**
 * _strpbrk - it locates first occurrence in a string of any of the specified delimiters.
 * @str: string to search.
 * @delimiters: delimiters to search for.
 *
 * Return: pointer to the first occurrence of a character or NULL if no match is found.
 */

char *_strpbrk(const char *str, const char *delimiters)
{
	while (*str != '\0')
	{
		const char *delimiter = delimiters;
		while (*delimiter != '\0')
		{
			if (*str == *delimiter)
				return (char *)str;
			delimiter++;
		}
		str++;
	}

	return (NULL);
}

/**
 *  * betty goes here
 *  */

char *_strtok(char *str, const char *delimiters)
{
	static char *nextToken = NULL;
	char *tokenStart;
	char *tokenEnd;

	if (str != NULL)
		nextToken = str;

	if (nextToken == NULL || *nextToken == '\0')
		return NULL;

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
 * _strtok - it tokenizes a string by breaking it into a sequence of tokens
 *           using the specified delimiters.
 * @str: string to tokenize.
 * @delimiters: delimiters for tokenizing the string.
 *
 * Return: Pointer to the next token found in 'str', or NULL
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


