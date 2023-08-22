#include "shell.h"

int commandExists(char *command)
{
	char *path = getenv("PATH");
	char *pathCopy = strdup(path);
	char *pathToken = strtok(pathCopy, ":");
	char fullPath[MAX_INPUT];

	if (path == NULL)
	{
		return (0);
	}

	while (pathToken != NULL)
	{

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
