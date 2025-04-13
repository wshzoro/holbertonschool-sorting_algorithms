#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * of integers in ascending order
 * @list: Double pointer to the head of the doubly linked list
 *
 * Description: Uses the Insertion sort algorithm
 * and prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *insert, *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;

while (current != NULL)
{
insert = current;
temp = current->next;
while (insert->prev != NULL && insert->n < insert->prev->n)
{
insert->prev->next = insert->next;

if (insert->next != NULL)
insert->next->prev = insert->prev;

insert->next = insert->prev;
insert->prev = insert->prev->prev;

insert->next->prev = insert;

if (insert->prev == NULL)
*list = insert;
else
insert->prev->next = insert;

print_list(*list);
}
current = temp;
}
}
