#include "shell.h"

/**
 * concat_path - Concatenate a path name and a program name.
 * @pathname: The path name to concatenate with the program name.
 * @progname: The program name to place in the path name.
 *
 * Return: The path name concatenated with the program name.
 */

char *concat_path(const char *pathname, const char *progname)
{
	size_t prog_len = strlen(progname);
	size_t path_len = strlen(pathname);
	size_t new_sz = path_len + prog_len + 2;
	char *new_path = realloc((char *)pathname, new_sz);

	if (!new_path)
	{
		perror("realloc failed");
		return (NULL);
	}

	snprintf(new_path + path_len, new_sz - path_len, "/%s", progname);

	return (new_path);
}

/**
 * find - Verify if a command is found in the system.
 * @cname: The command name to find in the system.
 *
 * Return: The path name of the command found or NULL if failed.
 */

char *find(char *cname)
{
	struct stat sb;
	int i;

	if (!cname)
	{
		return (NULL);
	}

	if (stat(cname, &sb) == 0)
	{
		return (cname);
	}

	if (cname[0] != '/')
	{
		char *env_path = getenv("PATH");
		int num_del = count_delims(env_path, ":");
		char **p_tokens = tokenize(env_path, ":", num_del);

		for (i = 0; i < num_del; i++) 
		{
			char *full_path = concat_path(p_tokens[i], cname);

			if (stat(full_path, &sb) == 0)
			{
				free(cname);
				frees_tokens(p_tokens);
				return (full_path);
			}

			free(full_path);
		}
		frees_tokens(p_tokens);
	}
	free(cname);
	return (NULL);
}

/**
 * exec - Executes a command.
 * @cname: The command to execute.
 * @opts: The options or flags to the command.
 *
 * Return: A integer status value.
 */
int exec(char *cname, char **opts, char **env) 
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("fork failed");
		return (-1);
	}
    else if (child == 0)
	{
		execve(cname, opts, env);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child, &status, 0);

		if (WIFEXITED(status))
		{
			return WEXITSTATUS(status);
		}
		else
		{
			perror("Child process didn't exit normally");
			return (-1);
		}
	}
}

