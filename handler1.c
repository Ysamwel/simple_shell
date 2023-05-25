#include "main.h"
#include "extern.h"

/**
 * execute_child - Executes the child process
 * @pathList: Pointer to the list of paths
 * @args: Array of command arguments
 * @program_name: Name of the program
 */
void execute_child(PathNode *pathList, char *args[], char *program_name)
{
	char **envp = environ;

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		execve(args[0], args, envp);
	}
	else
	{
		pathList = get_search_path();
		execute_path(pathList, args, program_name);
		free_paths(pathList);
	}

	exit(1);
}

/**
 * wait_child - Waits for the child process to complete and handles the result
 * @pid: Process ID of the child process
 * @args: Array of command arguments
 * @program_name: Name of the program
 */
void wait_child(pid_t pid, char *args[], char *program_name)
{
	int status;
	int exit_status;
	char *error_msg;

	waitpid(pid, &status, 0);

	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);

		if (exit_status != 0)
		{
			error_msg = Error(program_name, args[0], exit_status);
			write(STDERR_FILENO, error_msg, _strlen(error_msg));
			free(error_msg);
		}
	}
	else
	{
		exit_status = -1;
		error_msg = Error(program_name, args[0], exit_status);
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
		free(error_msg);
	}
}

/**
 * handle_execution - Executes a command by forking a child process
 * @pathList: Pointer to the list of paths
 * @args: Array of command arguments
 * @program_name: Name of the program
 */
void handle_execution(PathNode *pathList, char *args[], char *program_name)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		execute_child(pathList, args, program_name);
	}
	else
	{
		wait_child(pid, args, program_name);
	}
}
