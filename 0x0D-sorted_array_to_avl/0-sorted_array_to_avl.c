#include "binary_trees.h"

/**
 * insert_into_avl - Inserts an element in the AVL
 * @head: Current head
 * @value: new value to insert
 *
 * Return: New node
 **/
avl_t *insert_into_avl(avl_t *head, int value)
{
	avl_t *new = NULL;

	new = malloc(sizeof(avl_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = head;

	return (new);
}

/**
 * insert_start_end - Recursive fn Used to convert an array to AVL
 * @start: Head / from where to start
 * @array: array to convert to AVL
 * @first: Position where to start adding element
 * @last: Position where to stop adding element
 *
 * Return: Head of the AVL
 **/
avl_t *insert_start_end(avl_t *start, int *array, int first, int last)
{
	if (first > last)
	{
		return (NULL);
	}

	int mid = (first + last) / 2;
	avl_t *head;

	if (start == NULL)
	{
		head = insert_into_avl(NULL, array[mid]);
	}
	head = insert_into_avl(head, array[mid]);




	head->left = insert_start_end(head, array, first, mid - 1);
	head->right = insert_start_end(head, array, mid + 1, last);


	return (head);
}

/**
 * sorted_array_to_avl - Converts an array to AVL
 * @array: Array to convert
 * @size: Number of elements in the array
 *
 * Return: head of the AVL
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head = NULL;

	head = insert_start_end(NULL, array, 0, size - 1);
	if (head == NULL)
	{
		return (NULL);
	}

	return (head);
}