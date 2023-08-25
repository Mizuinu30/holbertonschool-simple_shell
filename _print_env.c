#include "shell.h"

/**
 * _print_env - Prints the environment built-in.
 *
 * Return: Nothing.
 */
void _print_env(void)
{
	int i;
	int j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			_putchar(environ[i][j]);
		}

		if (environ[i][0] != '\0')
			_putchar('\n');
	}
}

