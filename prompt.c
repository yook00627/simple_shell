#include "shell.h"

size_t _getline(char **str, size_t *size, FILE *stream)
{
	size_t i = 0;

	i = getline(str, size, stdin);
	/*null check needed*/
	return (i);
}

/**
 * prompt -
 *
 *
 *
 *
 */
int prompt(void)
{
	size_t buffsize = 0, i = 0, n = 0;
	int status = 0;
	pid_t pid = 0;
	char *command, **token;

	do {
		write(STDOUT_FILENO, "Kev Mel Shell$ ", 15);
		i = _getline(&command, &buffsize, stdin);
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		token = _strtok(command, " ");
		pid = fork();
		if (pid == 0)
		{

			exec(token);
		}
		else
		{
			wait(&status);
		}
	} while (0);
	return (i);
}
