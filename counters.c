#include "shell.h"

/**
 * count_input - Counts the words typed by the user.
 * @str: The string that contains the words.
 *
 * Return: The number of words found in the string.
 */

int count_input(char *str)
{
    int cw = 0, state = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            state = 0;
        else if (state == 0)
        {
            state = 1;
            cw++;
        }
    }

    return (cw);
}

/**
 * count_delims - Counts delimiters in a string
 * @str: The string that contains the delimiters
 * @del: The delimiters to search for in the string
 *
 * Return: The number of delimiters in the string
 */
int count_delims(char *str, char *del)
{
    int cw = 0;

    for (int i = 0; del[i]; i++)
    {
        for (int j = 0; str[j]; j++)
        {
            if (str[j] == del[i])
                cw++;
        }
    }

    return (cw);
}

