#include "shell.h"


/**
 *
 *
 *
 */

char *c_strdup(char *str, int cs)
{
	char *duplicate_str;
	int i = 0, len = 0;

	if (str == NULL) /* validate str input */
		return (NULL);

	while (*(str + i))
		len++, i++;

	len++; /* add null terminator to length */

	duplicate_str = malloc(sizeof(char) * (len - cs)); /* allocate memory */

	if (duplicate_str == NULL) /* validate memory */
		return (NULL);

	i = 0;
	while (i < (len - cs))
	{
		*(duplicate_str + i) = *(str + cs + i);
		i++;
	}
	return (duplicate_str);
}


char *path(char *str, char **env)
{
	int i = 0, si = 0, cs = 0;

	while (env[i] != NULL)
	{
		si = 0;
		while (env[i][si] == str[si])
		{
			si++;
		}
		if(str[si] == '\0')
		{
			break;
		}
		i++;
	}
	while (str[cs] != '\0')
		cs++;
	cs++;
	return (c_strdup(env[i], cs));
}


char *_which(char *str, char **env)
{
	char *pth, *cat, **toks;
	int i = 0, f = 0;

	pth = path("PATH", env);
	toks = _strtok(pth, ":");
	free(pth);
	while (toks[i] != NULL)
	{
		cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			while (toks[f] != NULL)
			{
				free(toks[f]);
				f++;
			}
			free(toks);
			return (cat);
		}
		free(cat);
		i++;
	}
	while (toks[f] != NULL)
	{
		free(toks[f]);
		f++;
	}
	free(toks);
	return (str);
}
/*test main*/
/*
void main (void)
{
	char *str;

	str = _which("ls");
	printf("%s\n", str);
	free(str);
}
*/
