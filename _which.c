#include "shell.h"

/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @str: first command user typed into shell (e.g. "ls" if user typed "ls -l")
 * @env: environmental variable
 * Return: a copy of fleshed out command (e.g. "/bin/ls" if originally "ls")
 */
char *_which(char *str, char **env)
{
	char *pth, *cat, **toks;
	int i = 0, f = 0;

	/* get and tokenize PATH directories, then free original string */
	pth = path("PATH", env);
	toks = _strtok(pth, ":");
	free(pth);

	/* append "/cmd" to each token to see it's legit */
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
