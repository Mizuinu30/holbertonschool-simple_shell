#include "shell.h"

/**
 * print_env - Prints the environment built-in
 * Return: Nothing to returns
 */

void _print_env(void)
{
    int i = 0, j = 0;

    while (environment[i])
    {
        j = 0;
        while (environment[i][j])
        {
            putchar(environment[i][j]);
            j++;
        }

        if (j != 0)
            putchar('\n');
        i++;
    }
}
