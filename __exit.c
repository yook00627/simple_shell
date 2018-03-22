#include "shell.h"

/**
 * c_atoi - custom atoi converts string to int
 * @s: string
 * Return: number if success, -1 if string contains non-numbers
 */
int c_atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9') /* calculate num */
			num = num * 10 + (s[i] - '0');
		if (s[i] > '9' || s[i] < '0') /* account for non-numbers */
			return (-1);
		i++;
	}
	return (num);
}

/**
 * __exit - frees user input and then exits main program with a value
 * @str: user's command into shell (e.g. "exit 99")
 */
void __exit(char **str)
{
	int n = 0, e_value = 0;

	if (str[1] != NULL) /* if no value given after exit, return 0 */
		e_value = c_atoi(str[1]);

	while (str[n] != NULL) /* free user input before exiting program */
	{
		free(str[n]);
		n++;
	}
	free(str);

	if (e_value == -1) /* if value given after exit is invalid, perror */
	{
		perror("Error:");
		return;
	}
	exit(e_value);
}
