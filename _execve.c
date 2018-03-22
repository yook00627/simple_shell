#include "shell.h"

void c_exit(char **str)
{
	int n = 0;

	while (str[n] != NULL) /* free user input before exiting program */
	{
		free(str[n]);
		n++;
	}
	free(str);
	_exit(0);
}

/**
 * _execve - execute command user typed into shell
 * @s: command user typed
 * @env: environmental variable
 * Return: 0 on success
 */
int _execve(char **s, char **env)
{
	char *holder;

	/* if access sees an existing legit full cmd path, it executes cmd */
	if (access(s[0], F_OK) == 0)
	{
		if (execve(s[0], s, NULL) == -1)
		{
			perror("Error1:");
			c_exit(s);
		}
	}
	/* else flesh out full path and execute command */
	else
	{
		holder = _which(s[0], env);
	}
	if (access(holder, F_OK) != 0)
	{
		perror("error");
		c_exit(s);
	}
	else
	{
		if (execve(holder, s, NULL) == -1)
		{
			perror("Error2:");
			c_exit(s); /* if not a legit cmd, free and exit */
		}
	}
	return (0);
}
