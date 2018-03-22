#include "shell.h"

char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * non_interactive -
 * @env: envrionmental variables
 */
void non_interactive(char **env)
{
	size_t i = 0, n = 0, f = 0;
	int status = 0;
	pid_t pid = 0;
	char *command, *n_command, **n_line, **token;

	command = NULL; /* reset command to NULL each time loop runs */
	i = 0;
	i = _getline(&command);
	if (i == 0)
	{
		free(command); /* exit with newline if in shell */
		exit(0);
	}
	n_command = command;
	command = c_ignore(command);
	n_line = NULL;
	n_line = _strtok(command, "\n");
	if (n_command != NULL)
		free(n_command);
	n = 0;
	while (n_line[n] != NULL)
	{
		token = NULL; /* tokenize user's typed in command */
		token = _strtok(n_line[n], " ");
		if (built_in(token, env))/*checks for built ins*/
		{
			n++;
			continue;
		}
		pid = fork(); /* create child process to execute cmd */
		if (pid == 0)
		{
			_execve(token, env);
		}
		else /* parent waits till child finishes & frees cmd tokens */
		{
			wait(&status);
			n++;
			f = 0;
			while (token[f] != NULL)
			{
				free(token[f]);
				f++;
			}
			free(token);
		}
	}
	n = 0;
	while (n_line[n] != NULL)
	{
		free(n_line[n]);
		n++;
	}
	free(n_line);
	exit(0);
}
