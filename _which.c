#include "shell.h"

char *path(char *str)
{
	int i = 0, si = 0;
	extern char **environ;

	while (environ[i] != NULL)
	{
		si = 0;
		while (environ[i][si] == str[si])
		{
			si++;
		}
		if(str[si] == '\0')
		{
			break;
		}
		i++;
	}
	return (environ[i]);
}


char *_which(char *str)
{
	char *env, *cat, **toks;
	int i = 0;

	env = path("PATH");
	printf("%d\n", i);
	toks = _strtok(env, ":");
	printf("%s\n", toks[i]);
	while (toks[i] != NULL)
	{
		cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			return (cat);
		}
		i++;
	}
	return (NULL);
}

int main(void)
{
	char *str;

	str = _which("ls");
	printf("%s\n", str);
	return (0);
}
