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

	j = 1;/*ignore the first character*/
	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}


void _cd(char **str, list_t *env)
{
	char *home;
	char *current = NULL;

	if (str[1] != NULL)
	{
		if (str[1][0] == '~')
		{
			current = get_env("HOME", env);
			current = c_strcat(current, str[1]);
		}
		else if (str[1][0] == '-')
		{

		}
		else
		{
			current = getcwd(current, 0);
			if (str[1][0] != '/')
			{
				current = _strcat(current, "/");
				current = _strcat(current, str[1]);
			}
			else
				current = _strcat(current, str[1]);
		}
		if (access(current, F_OK) == 0)
			chdir(current);
		else
			perror("Error:");
		free(current);
	}
	else
	{
		home = get_env("HOME", env);
		if (access(home, F_OK) == 0)
			chdir(home);
		else
			perror("Error:");
		free(home);
	}
	free_double_ptr(str); /* frees user input */
}
