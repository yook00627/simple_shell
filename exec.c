#include "shell.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int exec(char **s)
{
	if (execve(s[0], s, NULL) == -1)
	{
		perror("Error:");
	}
	return (0);
}
