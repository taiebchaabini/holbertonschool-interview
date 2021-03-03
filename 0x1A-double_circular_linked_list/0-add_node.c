#include "list.h"

/**
 * create_node - Creates a new node
 * @str: the string to copy into the new node
 * Return: A new node
 **/
List *create_node(char *str)
{
	List *node = malloc(sizeof(List));

	if (node == NULL)
		return (NULL);
	node->str = strdup(str);
	if (node->str == NULL)
		return (NULL);
	return (node);
}

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 **/
List *add_node_end(List **list, char *str)
{
	if (*list == NULL)
	{
		*list = create_node(str);
		if ((*list) != NULL)
			return (*list);
	}
	else
	{
		List *head = *list;
		List *end = create_node(str);

		if (end == NULL)
			return (NULL);

		if (head->prev == NULL)
			end->prev = head;

		while ((*list)->next && (*list)->next != head)
			(*list) = (*list)->next;

		end->prev = (*list);
		(*list)->next = end;
		head->prev = end;
		end->next = head;
		*list = head;

		return (end);
	}
	return (NULL);
}

/**
 * add_node_begin - Add a new node to the beginning of a
 * double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 **/
List *add_node_begin(List **list, char *str)
{
	if (*list == NULL)
	{
		*list = create_node(str);
		if ((*list) != NULL)
			return (*list);
	}
	else
	{
		List *head = *list;
		List *first = create_node(str);

		if (first == NULL)
			return (NULL);

		if (head->prev == NULL)
			first->prev = head;
		else
			first->prev = head->prev;

		first->next = head;
		head->prev = first;

		while ((*list)->next && (*list)->next != head)
			(*list) = (*list)->next;

		(*list)->next = first;
		*list = first;
		return (first);
	}
	return (NULL);
}
