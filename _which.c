#include "shell.h"

/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @str: first command user typed into shell (e.g. "ls" if user typed "ls -l")
 * @env: environmental variable
 * Return: a copy of fleshed out command (e.g. "/bin/ls" if originally "ls")
 */
char *_which(char *str, char **env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0, f = 0, t = 0;

	/* get and tokenize PATH directories, then free original string */
	pth = get_env("PATH", env);

	/*set t = 1 if we see double colon or beggining colon in path*/
	i = 1;
	while (pth[i] != '\0')
	{
		if (pth[i - 1] == ':')
		{
			if (pth[i] == ':')
				t = 1;
			else if (i == 1)
				t = 1;
		}
		i++;
	}
	/*check if command exist in cwd*/
	if (t == 1)
	{
		cat = getcwd(cat, 0);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			free(pth);
			return (cat);
		}
		free(cat); /* free concatenated string if cmd is never found */
	}
	toks = _strtok(pth, ":");
	free(pth);

	/* append "/cmd" to each token to see it's legit */
	i = 0;
	while (toks[i] != NULL)
	{
		cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			/* free tokens before returning legit fleshed path */
			while (toks[f] != NULL)
			{
				free(toks[f]);
				f++;
			}
			free(toks);
			return (cat);
		}
		free(cat); /* free concatenated string if cmd is never found */
		i++;
	}
	while (toks[f] != NULL)
	{
		free(toks[f]);
		f++;
	}
	free(toks);
	return (str); /* return random string if not found; won't pass execve */
}
