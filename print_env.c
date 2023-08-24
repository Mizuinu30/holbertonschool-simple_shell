#include "shell.h"

/**
 * print_env - Prints the environment built-in
 * Return: Nothing to returns
 */

void print_env(char **env)
{
    int i = 0, j = 0;

    while (env[i])
    {
        j = 0;
        while (env[i][j])
        {
            putchar(env[i][j]);
            j++;
        }

        if (j != 0)
            putchar('\n');
        i++;
    }
}
