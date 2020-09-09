#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: linked list to check.
 * Return: returns 1 if there is a cycle otherwise 0
**/
int check_cycle(listint_t *list){
	listint_t *head = list;

	if (list == NULL)
		return (0);
	while (list->next){
		if (list->next == head)
			return (1);
		list = list->next;
	}
	return (0);
}
