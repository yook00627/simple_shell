#include "shell.h"

/**
 * c_strdup - custom string duplication; excludes duplication of beginning bytes
 * @str: string to duplicate (e.g. environmental variable PATH=/bin:/bin/ls)
 * @cs: number of bytes to exclude (e.g. excludes "PATH=")
 * Return: string (e.g. /bin:/bin/ls)
 */
char *c_strdup(char *str, int cs)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL) /* validate str input */
		return (NULL);

	/* calculate len + null terminator to malloc */
	while (*(str + len))
		len++;
	len++;

	/* allocate memory but exclude environmental variable title (PATH) */
	duplicate_str = malloc(sizeof(char) * (len - cs));
	if (duplicate_str == NULL)
		return (NULL);

	i = 0;
	while (i < (len - cs))
	{
		*(duplicate_str + i) = *(str + cs + i);
		i++;
	}
	return (duplicate_str);
}

/**
 * path - finds and returns a copy of the requested environmental variable
 * @str: string to store it in
 * @cs: entire set of environmental variables
 * Return: copy of requested environmental variable
 */
char *path(char *str, char **env)
{
	int i = 0, j = 0, cs = 0;

	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] == str[j]) /* find desired env variable */
			j++;
		if(str[j] == '\0')
			break;
		i++;
	}

	while (str[cs] != '\0') /* find how many bytes in env variable title */
		cs++;
	cs++;
	return (c_strdup(env[i], cs)); /* make a copy of variable w/o title */
}
