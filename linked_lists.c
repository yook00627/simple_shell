#include "shell.h"

size_t print_list(list_t *h)
{
	list_t *c_list = h;
	int count = 0;

	if (h == NULL)
		return (0);
	while (c_list != NULL)
	{
		if (c_list->var == NULL)
			printf("[0] (nil)\n");
		else
			printf("%s\n", c_list->var);
		c_list = c_list->next;
		count++;
	}
	return (count);
}

list_t *add_end_node(list_t **head, char *str)
{
	list_t *new;
	list_t *holder;

	if (head == NULL || str == NULL)
		return (NULL);/*check if address of head is null*/
	new = malloc(sizeof(list_t));
	if (new == NULL)/*malloc check*/
		return (NULL);
	new->var = _strdup(str);
	new->next = NULL;
	holder = *head;
	if (holder != NULL)
	{
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new;
	}
	else
	{
		*head = new;
	}
	return (*head);
}

/**
 * delete_nodeint_at_index - removing node at index
 * @head: input head address
 * @index: input index
 * Return: 1 if succes -1 if fail
 */
int delete_nodeint_at_index(list_t **head, int index)
{
	list_t *n_head;
	list_t *holder;
	int count = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		holder = (*head)->next;
		free((*head)->var);
		free(*head);
		*head = holder;
		return (1);
	}
	count = 1;
	n_head = *head;
	while (count < index)
	{
		if (n_head == NULL)
			return (-1);
		n_head = n_head->next;
		count++;
	}
	holder = n_head->next;
	n_head->next = holder->next;
	free(holder->var);
	free(holder);
	return (1);
}

void free_linked_list(list_t *list)
{
	list_t *holder;

	while (list != NULL)
	{
		holder = list;
		list = list->next;
		free(holder->var);
		free(holder);
	}

}
