#include "main.h"

/**
 * Error - Generates an error message for a command not found
 * @program_name: Name of the program
 * @command: Command that was not found
 * @exit_status: Exit status of the command
 * Return: Pointer to the dynamically allocated error message string
 */
char *Error(const char *program_name, const char *command, int exit_status)
{
	char *error_msg = malloc(100);
	int i;
	int exit_status_length = 1;
	int temp_exit_status;
	char *exit_status_str;

	if (error_msg == NULL)
	{
		perror("malloc");
		exit(1);
	}
	_strncpy(error_msg, program_name, 100);
	_strcat(error_msg, ": ", 100);
	exit_status_length = 1;
	temp_exit_status = exit_status;
	while (temp_exit_status /= 10)
		exit_status_length++;
	exit_status_str = malloc(exit_status_length + 1);
	if (exit_status_str == NULL)
	{
		perror("malloc");
		free(error_msg);
		exit(1);
	}
	i = exit_status_length;
	exit_status_str[i--] = '\0';
	while (exit_status)
	{
		exit_status_str[i--] = '0' + (exit_status % 10);
		exit_status /= 10;
	}
	_strcat(error_msg, exit_status_str, 100);
	_strcat(error_msg, ": ", 100);
	_strcat(error_msg, command, 100);
	_strcat(error_msg, ": command not found\n", 100);
	free(exit_status_str);
	return (error_msg);
}
