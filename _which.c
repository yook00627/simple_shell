#include "shell.h"

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
