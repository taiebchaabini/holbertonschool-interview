#include "binary_trees.h"

int heap_swap(heap_t **root, heap_t *new)
{
    if ((*root)->n < new->n)
    {
        new->parent = (*root)->parent;
        (*root)->parent = new;
        new->left = (*root);
        *root = new;
        return 1;
    }
    return 0;
}

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

unsigned int heap_size(heap_t *head, unsigned int size)
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
    unsigned int size = 1, i = 0;
    int *binary, parent_pos, swap;

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
        parent_pos = binary[i + 1];
        new->parent = tmp;
        if (!tmp->left)
            tmp->left = new;
        else
            tmp->right = new;
        /** Make the swap if the value is greater **/
        while (new->n > new->parent->n){
            swap = new->n;
            new->n = new->parent->n;
            new->parent->n = swap;
            new = new->parent;
        }
    }
    else
    {
        *root = new;
    }
    return new;
}