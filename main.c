#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Success
 */

int main(void)
{
	char *line_ptr = NULL;
	size_t buffer = 0;
	ssize_t read_input;
	char *shellname;
	int status;
	int is_interactive;

	is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			shell_prompt();

		read_input = getline(&line_ptr, &buffer, stdin);

		if (read_input == -1)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		shellname = strtok(line_ptr, " \t\n");
		if (shellname == NULL)
		{
			continue;
		}
		status = execute_command(shellname);
		if (status == -1)
		{
			fprintf(stderr, "%s: Error executing command\n", shellname);
		}
		if (!is_interactive)
			break;
	}
	free(line_ptr);
	exit(EXIT_SUCCESS);
}
