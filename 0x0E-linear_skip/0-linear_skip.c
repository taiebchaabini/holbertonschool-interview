#include "search.h"

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

    if (list == NULL){
        return (NULL);
    }
    head = list;
    express = head->express;
   
    while (head->next){
     
        if (head->express){
            express = head->express;
            if (express->n > value){
                if (head->index != 0)
                    printf("Value checked at index [%ld] = [%d]\n", head->index, head->n);
                printf("Value checked at index [%ld] = [%d]\n", express->index, express->n);
                printf("Value found between indexes [%ld] and [%ld]\n", head->index, express->index);
                while (head){
                    printf("Value checked at index [%ld] = [%d]\n", head->index, head->n);
                    if (head->n == value)
                        return (head);
                    head = head->next;
                }
            } else{
                printf("Value checked at index [%ld] = [%d]\n", express->index, express->n);
            }
            head = express;
        } 
        head = head->next;
    }
    return (NULL);
}