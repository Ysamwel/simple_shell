#include "main.h"

/**
 * tokenize_command - commands into individual arguments.
 * @command: command string.
 * @args: array that stores arguments.
 */
void tokenize_command(char *command, char *args[])
{
	int num_args = 0;
	int i = 0;

	while (command[i] && (command[i] == ' ' || command[i] == '\t'))
		i++;

	while (command[i] && num_args < MAX_ARGS)
	{
		while (command[i] && (command[i] == ' ' || command[i] == '\t'))
			i++;

		if (command[i])
		{
			args[num_args] = &command[i];
			num_args++;

			while (command[i] && command[i] != ' ' && command[i] != '\t')
				i++;

			if (command[i])
			{
				command[i] = '\0';
				i++;
			}
		}
	}

	args[num_args] = NULL;
}

