#include "main.h"

/**
 * handle_execution - Executes a command by forking a child process
 * @pathList: Pointer to the list of paths
 * @args: Array of command arguments
 * @program_name: Name of the program
 */
void handle_execution(PathNode *pathList, char *args[], char *program_name)
{
	char *path;
	pid_t pid = fork();
	int exit_status;
	char *error_msg;

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		extern char **environ;
		char **envp = environ;

		pathList = NULL;
		path = _getenviron("PATH", envp);

		if (path != NULL)
		{
			char *dir = _strtok(path, ":");

			while (dir != NULL)
			{
				pathList = add_path(pathList, dir);
				dir = _strtok(NULL, ":");
			}
		}

		execute_path(pathList, args, program_name);
		free_paths(pathList);
		exit(1);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);

			if (exit_status != 0)
			{
				if (pid != 0)
				{
					error_msg = generate_command_not_found_error(program_name,
							args[0], exit_status);
					write(STDERR_FILENO, error_msg, _strlen(error_msg));
					free(error_msg);
				}
			}
		}
		else
		{
			if (pid != 0)
			{
				exit_status = -1;
				error_msg = generate_command_not_found_error(program_name, args[0],
						exit_status);
				write(STDERR_FILENO, error_msg, _strlen(error_msg));
				free(error_msg);
			}
		}
	}
}


/**
 * execute_path - Executes the command by searching for
 * executable in the given paths
 * @pathList: points to the list of paths
 * @args: an array of command arguments
 * @program_name: name to the program
 */
void execute_path(PathNode *pathList, char *args[], char *program_name
		__attribute__((unused)))
{
	char command_path[MAX_COMMAND_LENGTH];
	PathNode *currentPath = pathList;
	int found = 0;

	while (currentPath != NULL)
	{
		size_t dirLength = _strlen(currentPath->path);
		size_t commandLength = _strlen(args[0]);

		if (dirLength + 1 + commandLength + 1 <= MAX_COMMAND_LENGTH)
		{
			_strncpy(command_path, currentPath->path, MAX_COMMAND_LENGTH);
			command_path[dirLength] = '/';
			_strncpy(command_path + dirLength + 1, args[0],
					MAX_COMMAND_LENGTH - dirLength - 1);

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
