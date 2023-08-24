#include "shell.h"

/**
 * handle_exit - exits shell.
 * @u_tokens: tokens.
 * @line: line.
 *
 * Return: nothing.
 */

void handle_exit(char **u_tokens, char *line)
{
	int status = 0;

	if (u_tokens[1] == NULL || (!strcmp(u_tokens[1], "0")))
	{
		frees_tokens(u_tokens);
		printf("line1");
		free(line);
		exit(0);
	}
	status = atoi(u_tokens[1]);
	if (status != 0)
	{
		frees_tokens(u_tokens);
		printf("line2");
		free(line);
		exit(status);
	}
	else
	{
		puts("Exit: Wrong number:");
		puts(u_tokens[1]);
		puts("\n");
		exit(2);
	}
	frees_tokens(u_tokens);
	printf("line3");
	free(line);
	exit(EXIT_SUCCESS);
}
