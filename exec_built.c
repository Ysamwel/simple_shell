#include "main.h"
#include "extern.h"

/**
 * _atoi - Converts a string to an integer
 * @str: String to be converted
 * Return: The converted integer value
 */
int _atoi(char *str)
{
	int result = 0;
	int i = 0;
	int sign = 1;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		result = result * 10 + (str[i] - '0');
	}

	return (sign * result);
}

/**
 * my_exit - Exits the program with the specified status
 * @status: Exit status of the program
 */
void my_exit(int status)
{
	exit(status);
}

/**
 * exit_execute - Executes the exit command
 * @args: Array of command arguments
 * Return: 0
 */
int exit_execute(char **args __attribute__((unused)))
{
	if (args != NULL && args[0] != NULL)
	{
		int exit_code = 0;

		if (args[1] != NULL)
		{
			exit_code = atoi(args[1]);
		}
		exit(exit_code);
	}
	return (0);
}

/**
 * env_execute - Executes the env command
 * @args: Array of command arguments
 * Return: 0
 */
int env_execute(char **args __attribute__((unused)))
{
	int i = 0;

	while (environ[i] != NULL)
	{
		my_puts(environ[i], 1);
		i++;
	}

	return (0);
}
