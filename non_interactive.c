#include "shell.h"

/**
 * c_ignore - custom ignores spaces and newlines
 * (e.g. echo "ls\n ls" | ./a.out)
 * @str: envrionmental variables
 * Return: new string
 */
char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * non_interactive - handles when user pipes commands into shell via pipeline
 * (e.g. echo "ls/nls -al/n" | ./a.out)
 * @env: envrionmental variables
 */
void non_interactive(list_t *env)
{
	size_t i = 0, n = 0;
	int status = 0;
	pid_t pid = 0;
	char *command = NULL, *n_command = NULL, **n_line, **token;

	i = _getline(&command);
	if (i == 0)
	{
		free(command);
		exit(0);
	}
	n_command = command;
	command = c_ignore(command);
	n_line = _strtok(command, "\n"); /* Usage: echo "ls\nls -l" | ./a.out */
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
			_execve(token, env);
		else /* parent waits till child finishes & frees cmd tokens */
		{
			wait(&status);
			n++;
			free_double_ptr(token);
		}
	}
	free_double_ptr(n_line);
	free_linked_list(env);
	exit(0);
}
