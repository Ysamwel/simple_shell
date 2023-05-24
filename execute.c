#include "main.h"
#include "extern.h"

/**
 * execute_command - Executes the command
 * @command: Command by the user
 * @args: Argument vector
 * Return: void
 */
void execute_command(char *command, char *args[])
{
	static const builtin_f builtins[] = {
		{"exit", exit_execute},
		{"env", env_execute},
		{NULL, NULL}
	};

	int i;

	if (is_builtin(command))
	{
		return;
	}

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (c_strcmp(command, builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}

	execve(command, args, environ);
	perror("Execute error");
	exit(EXIT_FAILURE);
}

/**
 * is_builtin - Checks if the command is a built-in command
 * @command: Command by the user
 * Return: 1 if command is a built-in command, 0 otherwise
 */
int is_builtin(char *command)
{
	static const builtin_f builtins[] = {
		{"exit", exit_execute},
		{"env", env_execute},
		{NULL, NULL}
	};

	int i;

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (c_strcmp(command, builtins[i].name) == 0)
		{
			return (1);
		}
	}

	return (0);
}
