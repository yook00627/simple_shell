#include "shell.h"
#define BUFF_SIZE 64

size_t _getline(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[BUFF_SIZE];

	while (t2 == 0 && (i = read(STDIN_FILENO, buff, BUFF_SIZE - 1)))
	{
		buff[i] = '\0';
		n = 0;
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}
		if (i == -1)
			return (-1);
		if (t == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = strcpy(*str, buff);
			size = i;
			t = 1;
		}
		else
		{
			size += i;
			*str = _strcat(*str, buff);
		}
	}
	return (size);
}

/*
void main(void)
{
	char *s = NULL;

	i = _getline(&s);
	printf("%s\n", s);
}
*/

/*
size_t _getline(char **str, size_t *size, FILE *stream)
{
	size_t i = 0;

	i = getline(str, size, stdin);

	return (i);
}
*/
