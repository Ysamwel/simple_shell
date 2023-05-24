#include "main.h"

/**
 * my_prompt - Displays the user prompt
 * @prompt: Prompt entered
 * @append_newline: Whether to append a newline character
 * Return: void
 */
void my_prompt(char *prompt, bool append_newline)
{
	(void) prompt;

	my_puts("\033[1;34m[Yvon-Dave\033[1;33m~$]\033[0m# ", 0);

	if (append_newline)
	{
		my_puts("\n", 0);
	}
}
