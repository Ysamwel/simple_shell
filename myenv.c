#include "main.h"

/**
 * cmp_env_type - Compares the type of an environment variable
 * @tyenv: Environment variable string to compare
 * @type: Type string to compare against
 * Return: 0 if not equal, index of '=' character + 1 if equal
 */
int cmp_env_type(const char *tyenv, const char *type)
{
	int i;

	for (i = 0; tyenv[i] != '='; i++)
	{
		if (tyenv[i] != type[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenviron - Retrieves the value of an environment variable
 * @type: Type string of the environment variable to retrieve
 * @_env: Array of environment variables
 * Return: Pointer to the value of the environment
 * variable, or NULL if not found
 */
char *_getenviron(const char *type, char **_env)
{
	char *ptr_environ;
	int i, loc;

	ptr_environ = NULL;
	loc = 0;
	for (i = 0; _env[i]; i++)
	{
		loc = cmp_env_type(_env[i], type);
		if (loc)
		{
			ptr_environ = _env[i];
			break;
		}
	}

	return (ptr_environ + loc);
}

/**
 * _environ - Prints all environment variables
 * @datashell: Data shell structure
 * Return: Always 1
 */
int _environ(data_sh *datashell)
{
	int i, j;

	for (i = 0; datashell->_env[i]; i++)
	{
		for (j = 0; datashell->_env[i][j]; j++)
			;

		write(STDOUT_FILENO, datashell->_env[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datashell->status = 0;

	return (1);
}
