#include "shell.h"

/**
 * c_exit - frees user's typed command and linked list before exiting
 * @str: user's typed command
 * @env: input the linked list of envirnment
 */
void c_exit(char **str, list_t *env)
{
	free_double_ptr(str);
	free_linked_list(env);
	_exit(0);
}

/**
 * _execve - execute command user typed into shell
 * @s: command user typed
 * @env: environmental variable
 * @num: nth user command; to be used in error message
 * Return: 0 on success
 */
int _execve(char **s, list_t *env, int num)
{
	char *holder;

	/* if access sees an existing legit full cmd path, it executes cmd */
	if (access(s[0], F_OK) == 0)
	{
		if (execve(s[0], s, NULL) == -1)
		{
			not_found(s[0], num, env);
			c_exit(s, env);
		}
	}
	/* else flesh out full path */
	else
		holder = _which(s[0], env);

	/* execute command with full path */
	if (access(holder, F_OK) != 0)
	{
		not_found(s[0], num, env);
		c_exit(s, env);
	}
	else /* if not legit command, perror and exit */
	{
		if (execve(holder, s, NULL) == -1)
		{
			not_found(s[0], num, env); /* print special error msg */
			c_exit(s, env);
		}
	}
	return (0);
}
