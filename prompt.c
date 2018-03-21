#include "shell.h"


void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\nKev Mel Shell$ ", 16);

}

/**
 * prompt -
 *
 *
 *
 *
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
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Kev Mel Shell$ ", 15);
		signal(SIGINT, ctrl_c);/*makes ctrl+c not work*/
		command = NULL;
		i = 0;
		i = _getline(&command);
		if (i == 0)
		{
			free(command);
			if(isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		n = 0;
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		if (command[0] == '\0')
		{
			if (command != NULL)
				free(command);
			continue;
		}
		token = NULL;
		token = _strtok(command, " ");
		if (command != NULL)
			free(command);
		if (_strcmp(token[0], "exit") == 0)
		{
			__exit(token);
			continue;
		}
		if (_strcmp(token[0], "env") == 0)
		{
			_env(token, env);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			exec(token, env);
		}
		else
		{
			wait(&status);
			f = 0;
			while(token[f] != NULL)
			{
				free(token[f]);
				f++;
			}
			free(token);
		}
	} while (i > 0);
	return (0);
}
