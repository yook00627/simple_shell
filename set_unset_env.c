#include "shell.h"


int find_env(list_t *env, char *str)
{
	int j = 0, index = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j]) /* find desired env variable */
			j++;
		if (str[j] == '\0')
			break;
		env = env->next;
		index++;
	}
	if (env == NULL)
		return (-1);
	return (index);
}

int _unsetenv(list_t **env, char **str)
{
	int index = 0, j = 0;

	index = find_env(*env, str[1]);
	free_double_ptr(str);
	if (index == -1)
	{
		write(STDOUT_FILENO, "Cannot find", 11);
		return (-1);
	}
	j = delete_nodeint_at_index(env, index);
	if (j == -1)
	{
		write(STDOUT_FILENO, "Cannot find", 11);
		return (-1);
	}
	return (index);
}
/*
int _setenv(list_t **env, char **str)
{
	int index = 0, j = 0;

	index = find_env(*env, name);
	if (index == -1)
		add_end_node(env, value);
	else
	{

	}
}
*/
