#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm.
 * @list: A double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *loop_node;
    listint_t *loop_check;
    listint_t *tmp1;
    listint_t *tmp2;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
    {
        return;
    }

    loop_node = (*list)->next;
    while (loop_node != NULL)
    {
        loop_check = loop_node;
        while (loop_check->prev != NULL && loop_check->prev->n > loop_check->n)
        {
            tmp1 = loop_check->prev;
            tmp2 = loop_check;
            tmp1->next = tmp2->next;
            tmp2->prev = tmp1->prev;
            tmp1->prev = tmp2;
            tmp2->next = tmp1;

            if (tmp1->prev != NULL)
            {
                tmp1->prev->next = tmp2;
            }
            else
            {
                *list = tmp2;
            }
            if (tmp1->next != NULL)
            {
                tmp1->next->prev = tmp1;
            }
            print_list(*list);
            loop_check = tmp1;
        }
        loop_node = loop_node->next;
    }
}
