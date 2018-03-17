#include "shell.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int exec(char **s)
{
	if (access(s[0], F_OK) == 0)
	{
		if (execve(s[0], s, NULL) == -1)
			perror("Error:");
	}
	else
	{
		if (execve(_which(s[0]), s, NULL) == -1)
		{
			perror("Error:");
		}
	}
	return (0);
}
