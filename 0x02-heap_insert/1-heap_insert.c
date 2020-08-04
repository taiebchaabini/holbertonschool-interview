#include "binary_trees.h"

/**
 * heap_swap - swaps if the new child is lower than its parent 
 * @new: New value to be swapped
 * Return: Adress of the new value
**/
heap_t *heap_swap(heap_t *new)
{
    int swap = 0;
    /** Make the swap if the value is greater **/
    while (new->n > new->parent->n)
    {
        swap = new->n;
        new->n = new->parent->n;
        new->parent->n = swap;
        new = new->parent;
    }
    return new;
}

/**
 * convert_to_binary - Converts integer to a binary
 * @num: Integer value
 * Return: Binary values into array of integer
**/
int *convert_to_binary(int num){
    static int bin[10], i;

    for (i = 1; num > 0; i++){
        bin[i] = num % 2;
        num /= 2;
    }
    bin[0] = i - 2;
    bin[i - 1] = -1;

    return bin;
}

/**
* heap_size - Get numbers of element in a binary tree
* @head: Head of the binary tree
* @size: Current size of the binary tree
* Return: Size of the binary tree
**/
int heap_size(heap_t *head, int size)
{   
    if (head->left)
        size = heap_size(head->left, size + 1);

    if (head->right)
        size = heap_size(head->right, size + 1);
    return size;
}
/**
 * heap_insert - function that inserts a value into a Max Binary Heap.
 * @root: is a double pointer to the root node of the Heap.
 * @value: is the value store in the node to be inserted.
 * Return: returns a pointer to the inserted node, or NULL on failure.
**/
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new, *tmp = *root;
    int *binary, size = 1, i = 0;

    new = malloc(sizeof(heap_t));
    if (new == NULL)
        return NULL;
    new->n = value;
    new->left = NULL;
    new->right = NULL;
    if ((*root))
    {
        size = heap_size(*root, size);
        /*
        printf("Binary tree size is %d\n", size);
        */
        binary = convert_to_binary(size + 1);
        i = binary[0];
        while(i > 0){
            if (binary[i] == 0){
                if (tmp->left)
                    tmp = tmp->left;
            }
            else{
                if (tmp->right)
                    tmp = tmp->right;
            }
            i--;
        }
        /* parent_pos = binary[i + 1]; */
        new->parent = tmp;
        if (!tmp->left)
            tmp->left = new;
        else
            tmp->right = new;
        new = heap_swap(new);
    }
    else
        *root = new;
    return new;
}