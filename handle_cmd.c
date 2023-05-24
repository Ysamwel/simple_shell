#include "main.h"
/**
 * handle_command - Handles the execution of a command
 * @command: Command to execute
 * @program_name: Name of the program
 *
 * Return: None
 */
void handle_command(char *command, char *program_name)
{
	char *args[MAX_ARGS + 2];

	tokenize_command(command, args);

	if (args[0] != NULL)
	{
		if (_strcmp(args[0], "exit") == 0)
		{
			exit_execute(args);
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			env_execute(args);
		}
		else
		{
			PathNode *pathList = get_search_path();

			handle_execution(pathList, args, program_name);
			free_paths(pathList);
		}
	}
}

