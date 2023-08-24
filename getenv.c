#include "shell.h"

/**
 * getenv - obtains environment variable.
 * @name: the variable to obtain.
 *
 * Return: the content of the variable.
 */

char *getenv(const char *name)
{
	int i = 0;
	char *env_var = NULL;

	while (enviroment[i])
	{
		if (strncmp(name, environment[i], strlen(name)) == 0)
		{
			env_var = strdup(environment[i]);
			while (*env_var != '=')
				env_var++;

			++env_var;
			return (env_var);
		}
		i++;
	}
	return (NULL);
}

