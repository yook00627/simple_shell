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

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t _getline(char **str);
int prompt(int ac, char **av, char **env);
char **_strtok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_which(char *str, char **env);
void __exit(char **s);
int _execve(char *argv[], char **env);
int _env(char **str, char **env);
char *_strcpy(char *dest, char *src);
char *get_env(char *str, char **env);
void _cd(char **str, char **env);
int built_in(char **token, char **env);
void non_interactive(char **env);
char *ignore_space(char *str);

#endif
