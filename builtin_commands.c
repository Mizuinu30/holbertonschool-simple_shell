#include "shell.h"

/**
 * execBuiltInCommands - Executes a built-in command
 * @u_tokns: ...
 * @line: ...
 *
 * Return: 1 if is a built-in command or 0 if not
 */
int execBuiltInCommands(char **u_tokns, char *line)
{
    int i = 0;
    char *ListBuiltinCmds[] = { "exit", "cd", "help", "env", NULL };

    while (ListBuiltinCmds[i])
    {
        if (strcmp(u_tokens[0], ListBuiltinCmds[i]) == 0)
        {
            if (i == 0)
            {
                handle_exit(u_tokens, line);
                return (1);
            }
            else if (i == 1)
            {
                chdir(u_tokns[1]);
                return (1);
            }
            else if (i == 2)
            {
                open_help();
                return (1);
            }
            else if (i == 3)
            {
                print_env();
                return (1);
            }
            else
            {
                break;
            }
        }
        i++;
    }

    return (0);
}
