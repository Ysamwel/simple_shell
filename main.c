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

	if (interactive_mode || argc == 1)
	{

		run_loop(program_name);
	}

	return (0);
}
