#include "shell.h"

/**
 * t_strlen - returns token string length for mallocing
 * @str: a token
 * @pos: index position in user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: token length
 */
int t_strlen(char *str, int pos, char delm)
{
	int len = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++;
		len++;
	}
	return (len);
}

/**
 * t_size - returns number of delim
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: number of tokens
 */
int t_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
			num_delm++;
		i++;
	}
	return (num_delm);
}

/**
 * _strtok - tokenizes a string and returns an array of tokens
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: an array of tokens (e.g. {"ls", "-l", "/tmp"}
 */
char **_strtok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0;
	char **toks, d_ch;

	/* set variable to be delimeter character (" ") */
	d_ch = delm[0];

	/* malloc number of ptrs to store array of tokens, and NULL ptr */
	buffsize = t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);

	/* iterate from string index 0 to string ending index */
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		/* malloc lengths for each token ptr in array */
		len = t_strlen(str, si, d_ch);
		toks[p] = malloc(sizeof(char) * (len + 1));
		if (toks[p] == NULL)
			return (NULL);
		i = 0;
		while ((str[si] != d_ch) &&
		       (str[si] != '\0'))
		{
			toks[p][i] = str[si];
			i++;
			si++;
		}
		toks[p][i] = '\0'; /* null terminate each string in array */
		/* handle repeated delimeters; increment ptr after ("ls __-l")*/
		if (si < se && str[si + 1] != d_ch)
			p++;
		si++;
	}
	p++;
	toks[p] = NULL; /* set last array ptr to NULL */
	return (toks);
}
