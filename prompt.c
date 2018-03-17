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

	write(STDOUT_FILENO, "Kev Mel Shell$ ", 15);
	do {
		i = _getline(&command, &buffsize, stdin);
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		token = _strtok(command, " ");
		if (fork() == 0)
		{
			printf("I am child\n");
			exec(token);
		}
		else
		{
			printf("I am parent\n");
			wait(&status);
			while (token[n] != NULL)
			{
				free(token[n]);
				n++;
			}
			free(token);
			free(command);
		}
	} while (i > 0);
	return (i);
}
