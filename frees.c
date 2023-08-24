#include "shell.h"

/**
 * frees_get_env - frees and or gets the environment.
 * @env_path: The environment variable to frees.
 *Return: Nothing to returns.
 */

void frees_get_env(char *env_path)
{
    if (env_path != NULL)
    {
        printf("before free\n");
        free(env_path);
        printf("after free\n");
    }
    else
    {
        printf("env_path is NULL\n");
    }
}

/**
 * frees_tokens - frees tokens.
 * @tokens: tokens.
 *Return: Nothing to returns.
 */

void frees_tokens(char **tokens)
{
    char **temp = tokens;

    if (tokens)
    {
        while (*tokens)
        {
            printf("inside while");
            free(*tokens);
            tokens++;
        }
        free(temp);
    }
}

