#include "shell.h"

int _env(char **str, char **env)
{
	int n = 0, c = 0;

	while (str[n] != NULL)
	{
		free(str[n]);
		n++;
	}
	free(str);
	n = 0;
	while (env[n] != NULL)
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
