#include "shell.h"

/**
  * concat_path - Concatenate a path name and a program name.
  * @pathname: The path name to concatenate with the program name.
  * @progname: The program name to place in the path name.
  *
  * Return: The path name concatenated with the program name.
  */
char *concat_path(char *pathname, char *progname)
{
	int prog_len = 0, path_len = 0, new_sz = 0;

	prog_len = strlen(progname);
	path_len = strlen(pathname);
	new_sz = sizeof(char) * (path_len + prog_len + 2);
	pathname = realloc(pathname, (path_len + 1) * new_sz);
	if (!pathname)
		return (NULL);

	strcat(pathname, "/");
	strcat(pathname, progname);

	return (pathname);
}

/**
  * find - Verify if a command is found in the system.
  * @cname: The command name to find in the system.
  *
  * Return: The path name of the command found or NULL if failed.
  */
char *find(char *cname)
{
	char *env_path = NULL, **p_tokens = NULL;
	int i = 0, num_del = 0;
	struct stat sb;

	if (cname)
	{
		if (stat(cname, &sb) != 0 && cname[0] != '/')
		{
			env_path = getenv("PATH");
			num_del = count_delims(env_path, ":") + 1;
			p_tokens = tokenize(env_path, ":", num_del);

			while (p_tokens[i])
			{
				p_tokens[i] = concat_path(p_tokens[i], cname);

				if (stat(p_tokens[i], &sb) == 0)
				{
					free(cname);
					cname = strdup(p_tokens[i]);
					frees_get_env(env_path);
					frees_tokens(p_tokens);
					return (cname);
				}

				i++;
			}

			frees_get_env(env_path);
			frees_tokens(p_tokens);
		}

		if (stat(cname, &sb) == 0)
			return (cname);
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

	switch (child = fork())
	{
		case -1:
			perror("fork failed");
			return (-1);
		case 0:
			execve(cname, opts, env);
			break;
		default:
			do {
				waitpid(child, &status, WUNTRACED);
			} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}

	return (0);
}
