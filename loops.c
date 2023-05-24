#include "main.h"

/**
 * run_loop - Runs the main loop for command execution
 * @program_name: Name of the program
 * Return: void
 */
void run_loop(char *program_name)
{
	char *command = NULL;
	size_t command_size = 0;
	size_t length;

	for (;;)
	{
		my_prompt(NULL, 0);
		fflush(stdout);

		if (custom_getLine(&command, &command_size, stdin) == -1)
		{
			break;
		}

		length = _strlen(command);
		if (length > 0 && command[length - 1] == '\n')
		{
			command[length - 1] = '\0';
		}

		handle_command(command, program_name);
	}

	free(command);
}

