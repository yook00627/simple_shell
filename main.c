#include "shell.h"

/**
 * main - creates a sipmle shell
 * @ac: argument count
 * @av: argument vectors
 * @env: environmental variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	prompt(ac, av, env);
	return (0);
}
