#include "shell.h"

list_t *env_linked_list(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}

/*
void main(int ac, char **av, char **env)
{
	list_t *list;
	(void)ac;
	(void)av;

	list = env_linked_list(env);
	print_list(list);
}
*/
