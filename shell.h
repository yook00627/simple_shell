#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

int exec(char *argv[]);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *str, char *delm);
int prompt(void);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_which(char *str);
size_t _getline(char **str, size_t *size, FILE *stream);

#endif
