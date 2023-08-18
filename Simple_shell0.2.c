#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * commandExists - 
 * @command:
 * Return: 0 
 */

int commandExists(char *command)
{
	char *path = getenv("PATH");
	if (path == NULL)
	{
		return (0);
	}

	char *pathCopy = strdup(path);
	char *pathToken = strtok(pathCopy, ":");

	while (pathToken != NULL)
	{
		char fullPath[MAX_INPUT_SIZE];
		snprintf(fullPath, sizeof(fullPath), "%s/%s", pathToken, command);

		if (access(fullPath, X_OK) == 0)
		{
			free(pathCopy);
			return (1);
		}

		pathToken = strtok(NULL, ":");
	}

	free(pathCopy);
	return (0);
}
