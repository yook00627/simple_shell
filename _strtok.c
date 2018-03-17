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

int t_size(char *str, char delm)
{
	int i = 0, count = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
			count++;
		i++;
	}
	return (count);
}


char **_strtok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0;
	char **toks, d_ch;

	d_ch = delm[0];
	buffsize = t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	while (str[se] != '\0')
		se++;
	while (si < se)
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
		if (si < se && str[si + 1] != d_ch)
			p++;
		si++;
	}
	p++;
	toks[p] = NULL;
	return toks;
}
