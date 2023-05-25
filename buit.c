#include "main.h"

/**
 * exec_builtin_command - Executes a builtin command
 * @tokens: Array of command tokens
 * Return: Status code of the command execution
 */
int exec_builtin_command(char **tokens)
{
	unsigned int num;
	unsigned int i;

	static const builtin_f builtins[] = {
		{"exit", exit_execute},
		{"env", env_execute},
	};

	if (tokens[0] == NULL)
		return (1);

	num = count_builtins((builtin_f *)builtins);
	for (i = 0; i < num; i++)
	{
		if (c_strcmp(tokens[0], builtins[i].name) == 0)
		{
			return (builtins[i].func(tokens));
		}
	}
	return (1);
}

/**
 * count_builtins - Counts the number of builtin commands
 * @builtins: Array of builtin commands
 * Return: Number of builtin commands
 */
unsigned int count_builtins(builtin_f *builtins)
{
	unsigned int i = 0;

	while (builtins[i].name != NULL)
		i++;

	return (i);
}

/**
 * c_strcmp - Custom string comparison function
 * @str1: First string
 * @str2: Second string
 * Return: 0
 */
int c_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}





