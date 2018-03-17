#include "shell.h"

int t_strlen(char *str, int pos, char delm)
{
	int i = 0;

	while ((str[pos] != delm) &&
	       (str[pos] != '\0'))
	{
		pos++;
		i++;
	}
	return (i);
}


char **_strtok(char *str, char *delm)
{
	int buffsize = 8, p = 0, si = 0, i = 0, len = 0;
	char **toks, d_ch;

	toks = malloc(sizeof(char *) * buffsize);
	d_ch = delm[0];
	while (str[si] != '\0')
	{
		len = t_strlen(str, si, d_ch);
		toks[p] = malloc(sizeof(char) * (len + 1));
		i = 0;
		while ((str[si] != d_ch) &&
		       (str[si] != '\0'))
		{
			toks[p][i] = str[si];
			i++;
			si++;
		}
		toks[p][i] = '\0';
		if (str[si + 1] != d_ch)
			p++;
		si++;
		if (p >= buffsize)
		{
			toks = _realloc(toks, buffsize,
					sizeof(char *) * (buffsize << 1));
			buffsize = buffsize << 1;
		}
	}
	toks[p] = NULL;
	return toks;
}
