#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include "math.h"
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>

#define BLUE_COLOR "\033[1;34m"
#define YELLOW_COLOR "\033[1;33m"
#define RESET_COLOR "\033[0m"
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

/**
 * struct datashell - Represents a shell data structure
 * @args: Arguments of the shell command
 * @_env: Environment variables
 * @status: Status of the shell command execution
 */
typedef struct datashell
{
	char **args;
	char **_env;
	int status;
} data_sh;

typedef int bool;
#define true 1
#define false 0
#define  BUFSIZE 1024

/**
 * struct PathNode - Represents a node in the search path linked list
 * @path: Path string
 * @next: Pointer to the next node
 */
typedef struct PathNode
{
	char path[MAX_COMMAND_LENGTH];
	struct PathNode *next;
} PathNode;

typedef int (*builtin_func)(char **args);

/**
 * struct builtin_s - Represents a builtin command
 * @name: Name of the command
 * @func: Pointer to the corresponding function
 */
typedef struct builtin_s
{
	const char *name;
	builtin_func func;
} builtin_f;

void my_prompt(char *prompt, bool append_newline);
void run_loop(char *program_name);
void tokenize_command(char *command, char *args[]);
void handle_command(char *command, char *program_name);
void handle_execution(PathNode *pathList, char *args[], char *program_name);
int my_puts(const char *str, bool append_newline);
void my_prompt(char *prompt, bool append_newline);
char *custom_getenv(const char *name);
void _memcpy(void *aftptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, size_t size);
PathNode *add_path(PathNode *head, const char *path);
void free_paths(PathNode *head);
PathNode *tokenize_path(const char *path);
PathNode *get_search_path(void);
void execute_command(char *command, char *args[]);
void wait_child(pid_t pid, char *args[], char *program_name);
void wait_child(pid_t pid, char *args[], char *program_name);
void execute_path(PathNode *pathList, char *args[], char *program_name);
void processLine(char **linptr, size_t *g, char *buff, size_t l);
ssize_t custom_getLine(char **linptr, size_t *g, FILE *stream);
unsigned int _strspn(char *s, char *accept);
void set_string(char **s, char *to);
char *_strchr(char *s, char c);
int c_strcmp(const char *str1, const char *str2);
int _strlen(char *s);
char *cap_string(char *s);
unsigned int _strspn(char *s, char *accept);
char *string_toupper(char *s);
void rev_string(char *s);
char *_strcat(char *dest, const char *src, size_t n);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *_strpbrk(const char *str, const char *delimiters);
char *_strtok(char *str, const char *delimiters);
char *_strncpy(char *destination, const char *source, size_t num);
char *s_strcpy(char *dest, const char *src);
void handle_cd_command(char *args[]);

void _memcpy(void *aftptr, const void *ptr, unsigned int size);
char **_reallocdp(char **ptr, unsigned int prev_size, unsigned int aft_size);
void get_err(data_sh *datashell, int err_num);

/* Handling Errors */

char *Error(const char *program_name, const char *command, int exit_status);
char *copy_inf(char *type, char *val);
void set_environ(char *type, char *val, data_sh *datashell);
int _setenviron(data_sh *datashell);
int _unsetenviron(data_sh *datashell);
int cmp_env_type(const char *tyenv, const char *type);
char *_getenviron(const char *type, char **_env);
int _environ(data_sh *datashell);
int help_gen(data_sh *datashell);
void aux_help_general(void);
void aux_help_setenviron(void);
void aux_help_environ(void);
void aux_help_unsetenviron(void);
void aux_help_exit(void);
void aux_help_cd(void);
void aux_help_alias(void);
int exit_execute(char **args);
int is_builtin(char *command);
int env_execute(char **args);
unsigned int count_builtins(builtin_f builtins[]);
int exec_builtin_command(char **tokens);
void _memcpy(void *aftptr, const void *ptr, unsigned int size);
void get_err(data_sh *datashell, int err_num);


#endif
