#include "shell.h"

void __exit(char **str)
{
	int n = 0;

	while (str[n] != NULL)
	{
		free(str[n]);
		n++;
	}
	free(str);
	exit(0);
}
