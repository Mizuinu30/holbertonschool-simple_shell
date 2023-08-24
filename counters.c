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
	int i;
	for (i = 0; str[i]; i++)
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
int count_delims(const char *str, const char *del)
{
	int count = 0;
	int j;
	int i;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; del[j]; j++)
		{
			if (str[i] == del[j])
			{
				count++;
				break;
			}
		}
	}

	return count;
}

