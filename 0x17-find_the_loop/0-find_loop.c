#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: Pointer to first node of a linked list
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 **/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tmp;
	listint_t *next;

	while (head->next)
	{
		tmp = head;

		if (head->next == tmp)
			return (head);

		next = head->next;
		head->next = tmp;
		head = next;
	}

	return (NULL);
}
