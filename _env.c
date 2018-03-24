#include "shell.h"

/**
 * _env - prints environmental variables
 * @str: user's command into shell (i.e. "env")
 * @env: environmental variables
 * Return: 0 on success
 */
int _env(char **str, list_t *env)
{
	free_double_ptr(str); /* frees user input */
	print_list(env); /* prints env */
	return (0);
}
