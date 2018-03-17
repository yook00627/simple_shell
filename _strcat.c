#include "shell.h"
/**
 * _strcat - concatenate two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */

char *_strcat(char *dest, char *src)
{
        int i = 0;
	int x = 0;
        int j = 0;
	int y = 0;

        while (dest[i] != '\0')
	{
		x++;
                i++;
	}
	while (src[y] != '\0')
	{
		y++;
		x++;
	}
	x++;
	dest = _realloc(dest, i, sizeof(char) * x);
        while (src[j] != '\0')
        {
                dest[i] = src[j];
                i++;
                j++;
        }
        dest[i] = '\0';

        return (dest);
}
