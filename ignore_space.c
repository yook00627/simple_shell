#include "shell.h"


char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}
