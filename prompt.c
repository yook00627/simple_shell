#include "shell.h"

/**
 * ctrl_c - ignore Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */
void ctrl_c(int n)
{
	(void)n;

	write(STDOUT_FILENO, "\nKev Mel Shell$ ", 16);
}

/**
 * prompt - repeatedly prompts user and executes user's cmds if applicable
 * @ac: argument count
 * @av: argument vectors
 * @env: envrionmental variables
 * Return: 0 on success
 */
int prompt(int ac, char **av, char **env)
{
	size_t i = 0, n = 0, f = 0;
	int status = 0;
	pid_t pid = 0;
	char *command, **token;

	(void)ac;
	(void)av;

	do {
		if (isatty(STDIN_FILENO)) /* reprompt if in interactive shell */
			write(STDOUT_FILENO, "Kev Mel Shell$ ", 15);
		signal(SIGINT, ctrl_c); /*makes ctrl+c not work*/

		command = NULL; /* reset command to NULL each time loop runs */
		i = 0;
		i = _getline(&command);
		if (i == 0)
		{
			free(command); /* exit with newline if in shell */
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		n = 0;
		while (command[n] != '\n') /* replace getline's \n with \0 */
			n++;
		command[n] = '\0';

		if (command[0] == '\0') /* reprompt if user hits enter only */
		{
			if (command != NULL)
				free(command);
			continue;
		}
		token = NULL; /* tokenize user's typed in command */
		token = _strtok(command, " ");
		if (command != NULL)
			free(command);

		/* if user types "exit", free cmd tokens, and exit */
		if (_strcmp(token[0], "exit") == 0)
			__exit(token);

		/* if user types "env", print, free cmd tokens, and reprompt */
		if (_strcmp(token[0], "env") == 0)
		{
			_env(token, env);
			continue;
		}

		pid = fork(); /* create child process to execute cmd */
		if (pid == 0)
		{
			exec(token, env);
		}
		else /* parent waits till child finishes & frees cmd tokens */
		{
			wait(&status);
			f = 0;
			while (token[f] != NULL)
			{
				free(token[f]);
				f++;
			}
			free(token);
		}
	} while (i > 0); /* keep on repeating till user exits shell */

	return (0);
}
