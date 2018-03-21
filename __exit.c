#include "shell.h"


/**
 * c_atoi - convert string to int
 *
 * @s: Value of input of string
 *
 * Return: return the int
 */
int c_atoi(char *s)
{
	int count = 0;
	unsigned int tmp = 0;
	int tmp_n = 1;

	while (s[count] != '\0')
	{
		if (s[count] >= '0' && s[count] <= '9')
			tmp = tmp * 10 + (s[count] - '0');
		if (s[count] > '9' || s[count] < '0')
			return (-1);
		count++;
	}
	return (tmp = tmp * tmp_n);
}

void __exit(char **str)
{
	int n = 0, e_value = 0;

	if (str[1] != NULL)
		e_value = c_atoi(str[1]);
	while (str[n] != NULL)
	{
		free(str[n]);
		n++;
	}
	free(str);
	if (e_value == -1)
	{
		perror("Error:");
		return;
	}
	exit(e_value);
}
