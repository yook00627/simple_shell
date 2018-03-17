#include "shell.h"

size_t _getline(char **str, size_t *size, FILE *stream)
{
	size_t i = 0;

	i = getline(str, size, stdin);
	/*null check needed*/
	return (i);
}
