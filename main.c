#include "main.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i;
	int interactive_mode = isatty(STDIN_FILENO);
	char *program_name = argc > 0 ? argv[0] : "hsh";

	if (argc > 1)
	{
		/* Execute command-line arguments */
		for (i = 1; i < argc; i++)
		{
			handle_command(argv[i], program_name);
		}
	}

	if (!interactive_mode && argc == 1)
	{
		/* Read commands from stdin and execute them */
		char *command = NULL;
		size_t bufsize = 0;
		ssize_t characters_read;

		while ((characters_read = custom_getLine(&command, &bufsize, stdin)) != -1)
		{
			if (characters_read > 0 && command[characters_read - 1] == '\n')
				command[characters_read - 1] = '\0'; /* Remove newline character */

			handle_command(command, program_name);
		}

		free(command);
	}
	else if (interactive_mode)
	{
		run_loop(program_name);
	}

	return (0);
}
