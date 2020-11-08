#include "search.h"

/**
 * print_checked - Prints the index and value on which the value is checked.
 * @first: index.
 * @second: value
 **/
void print_checked(size_t first, int second)
{
	printf("Value checked at index [%ld] = [%d]\n", first, second);
}

/**
 * print_found - Prints between which indexes the value has been found
 * @first: first index value
 * @second: second index value
 **/
void print_found(size_t first, size_t second)
{
	printf("Value found between indexes [%ld] and [%ld]\n", first, second);
}


/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in
 * @value: the value to search for
 *
 * Return: pointer on the first node where value is located
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *head;
	skiplist_t *express;
	skiplist_t *next;

	if (list == NULL)
		return (NULL);

	head = list;
	express = head->express;

	while (head->next)
	{
		if (head->express)
		{
			express = head->express;
			if (express->n > value)
			{
				if (head->index != 0)
					print_checked(head->index, head->n);
				print_checked(express->index, express->n);
				print_found(head->index, express->index);
				while (head)
				{
					print_checked(head->index, head->n);
					if (head->n == value)
						return (head);
					head = head->next;
				}
			}
			else
				print_checked(express->index, express->n);
			head = express;
		}
		head = head->next;
	}
	return (NULL);
}
