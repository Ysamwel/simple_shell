#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to evaluate.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: Less than 0 if s1 is less than s2, 0 if they're equal,
 *         more than 0 if s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string.
 * @c: The target character.
 *
 * Return: Pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

/**
 * rev_string - Reverses a string.
 * @s: The string to reverse.
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
 * string_toupper - Converts all lowercase characters in a string to uppercase.
 * @s: The string to convert.
 *
 * Return: Pointer to the resulting string.
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

