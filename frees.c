#include "shell.h"

/**
 * frees_get_env - frees and or gets the environment.
 * @env_path: The environment variable to frees.
 *Return: Nothing to returns.
 */

void frees_get_env(char *env_path)
{
    int i;

    for (i = 4; i >= 0; i--)
        env_path--;

    free(env_path);
}

/**
 * frees_tokens - frees tokens.
 * @tokens: tokens.
 *Return: Nothing to returns.
 */

void frees_tokens(char tokens)
{
    char temp = tokens;

    if (tokens)
    {
        while (tokens)
            free(tokens++);

        free(temp);
    }
}
