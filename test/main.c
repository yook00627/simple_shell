#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int c = 0, i = 0;
	char **str;

	str = malloc(sizeof(char *) * 4);
	while (c < 4)
	{
		str[c] = malloc(sizeof(char) * 10);
		i = 0;
		while (i < 10)
		{
			str[c][i] = '#';
			i++;
		}
		str[c][i - 1] = c + '0';
		str[c][i] = '\0';
		c++;
	}
	str[c] = NULL;
	c = 0;
	while (str[c] != NULL)
	{
		printf("%s\n", str[c]);
		c++;
	}

	free(str[1]);
	c = 0;
	while (str[c] != NULL)
	{
		if (str[c][0] != '\0')
			printf("%s\n", str[c]);
		c++;
	}

}
