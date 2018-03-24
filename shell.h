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

/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

/* function prototypes */
int prompt(char **env);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t _getline(char **str);
int t_strlen(char *str, int pos, char delm);
char *ignore_space(char *str);
char **_strtok(char *str, char *delm);
char **c_strtok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _cd(char **str, list_t *env);
int built_in(char **token, list_t *env);
void non_interactive(list_t *env);
char *_which(char *str, list_t *env);
void __exit(char **s);
int _execve(char *argv[], list_t *env);
void free_double_ptr(char **str);
void free_linked_list(list_t *list);
int _env(char **str, list_t *env);
char *get_env(char *str, list_t *env);
list_t *env_linked_list(char **env);
list_t *add_end_node(list_t **head, char *str);
size_t print_list(list_t *h);
int delete_nodeint_at_index(list_t **head, int index);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
int find_env(list_t *env, char *str);

#endif
