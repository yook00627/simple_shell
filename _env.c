#include "shell.h"

/**
 * _env - prints environmental variables
 * @str: user's command into shell (i.e. "env")
 * @env: environmental variables
 * Return: 0 on success
 */
int _env(char **str, char **env)
{
	int n = 0, c = 0;

	while (str[n] != NULL) /* frees user input */
	{
		free(str[n]);
		n++;
	}
	free(str);

	n = 0;
	while (env[n] != NULL) /* prints env */
	{
		c = 0;
		while (env[n][c] != '\0')
			c++;
		write(STDOUT_FILENO, env[n], c);
		write(STDOUT_FILENO, "\n", 1);
		n++;
	}

	return (0);
}
