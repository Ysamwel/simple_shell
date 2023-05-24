#include "main.h"
/**
 * execute_path - Executes a command by searching it
 * @pathList: Pointer to the list of paths to search
 * @args: Array of command arguments
 * @program_name: Name of the program (unused)
 */
void execute_path(PathNode *pathList, char *args[], char *program_name)
{
	PathNode *currentPath = pathList;
	int found = 0;
	char command_path[MAX_COMMAND_LENGTH];

	while (currentPath != NULL)
	{
		size_t dirLength = _strlen(currentPath->path);
		size_t commandLength = _strlen(args[0]);
		size_t r_len = MAX_COMMAND_LENGTH - dirLength - 1;

		if (dirLength + 1 + commandLength + 1 <= MAX_COMMAND_LENGTH)
		{
			_strncpy(command_path, currentPath->path, MAX_COMMAND_LENGTH);
			command_path[dirLength] = '/';
			_strncpy(command_path + dirLength + 1, args[0], r_len);

			if (access(command_path, F_OK) == 0)
			{
				execute_command(command_path, args);
				found = 1;
				break;
			}
		}

		currentPath = currentPath->next;
	}

	if (!found)
	{
		exit(1);
	}
	(void)program_name;
}

/**
 * handle_command - Handles the execution of a command
 * @command: Command string
 * @program_name: Name of the program
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
			PathNode *pathList = NULL;

			handle_execution(pathList, args, program_name);
		}
	}
}
