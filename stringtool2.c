#include "main.h"
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
