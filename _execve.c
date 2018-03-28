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
	int status = 0;
	pid_t pid;

	/* if access sees an existing legit full cmd path, it executes cmd */
	if (access(s[0], F_OK) == 0)
		holder = s[0];
	/* else flesh out full path */
	else
		holder = _which(s[0], env);

	if (access(holder, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_double_ptr(s);
		return (127);
	}
	/* execute command with full path */
	else /* if not legit command, perror and exit */
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(holder, s, NULL) == -1)
			{
				not_found(s[0], num, env); /* write special error msg */
				c_exit(s, env);
			}
		}
		else
		{
			wait(&status);
			free_double_ptr(s);
		}
	}
	return (0);
}
