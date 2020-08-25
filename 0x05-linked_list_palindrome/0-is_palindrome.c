#include "lists.h"
#include <stdio.h>
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: double linked list to check.
 * Return: 1 if it's palindrome otherwise 0.
 **/
int is_palindrome(listint_t **head)
{
	listint_t *oldHead = *head;
	listint_t *pt1 = *head;
	int counter = 0, i = 0;

	for (i = 0; oldHead; i++)
		oldHead = oldHead->next;
	oldHead = pt1;
	while (oldHead)
	{
		if (oldHead->next && oldHead->next->next == NULL)
		{
			if (pt1->n == oldHead->next->n)
			{
				oldHead->next = NULL;
				pt1 = pt1->next;
				oldHead = pt1;
				counter += 2;
			}
		}
		else if (counter != 0 && pt1->n == oldHead->n)
			counter += 2;
		oldHead = oldHead->next;
	}
	if (pt1->next == NULL)
		counter++;
	if (counter == i)
		return (1);
	return (0);
}
