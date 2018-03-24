#include "shell.h"

/**
 * c_strcat - concatenate two strings ignoring the first character
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char *c_strcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int total_len = 0;
	int j = 0;

	/* find total length of both strings to realloc */
	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	/* realloc because dest was malloced outside of function */
	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	j = 1; /* ignore the first character */
	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}

int c_setenv(list_t **env, char *name, char *dir)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	cat = _strdup(name);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, dir);
	index = find_env(*env, name);
	holder = *env;
	while (j < index)
	{
		holder = holder->next;
		j++;
	}
	free(holder->var);
	holder->var = _strdup(cat);
	free(cat);
	return (0);
}

/**
 * _cd - change directory
 * @str: user's typed in command
 * @env: enviromental linked list to retrieve HOME path
 */
void _cd(char **str, list_t *env)
{
	char *home = NULL, *current = NULL, *dir = NULL;

	current = getcwd(current, 0);
	if (str[1] != NULL)
	{
		if (str[1][0] == '~') /* Usage: cd ~ */
		{
			dir = get_env("HOME", env);
			dir = c_strcat(dir, str[1]);
		}
		else if (str[1][0] == '-') /* Usage: cd - */
		{
			if (str[1][1] == '\0')
				dir = get_env("OLDPWD", env);
		}
		else /* Usage: cd directory1 */
		{
			dir = getcwd(dir, 0);
			if (str[1][0] != '/')
				dir = _strcat(dir, "/");
			dir = _strcat(dir, str[1]);
		}
		c_setenv(&env, "OLDPWD", current);
		free(current);
		if (access(dir, F_OK) == 0)
			chdir(dir);
		else
			perror("Error:");
		current = NULL;
		current = getcwd(current, 0);
		c_setenv(&env, "PWD", current);
	}
	else /* Usage: cd */
	{
		home = get_env("HOME", env);
		c_setenv(&env, "OLDPWD", current);
		free(current);
		if (access(home, F_OK) == 0)
			chdir(home);
		else
			perror("Error:");
		current = NULL;
		current = getcwd(current, 0);
		c_setenv(&env, "PWD", current);
		free(home);
	}
	free(current);
	free_double_ptr(str); /* frees user input */
}
