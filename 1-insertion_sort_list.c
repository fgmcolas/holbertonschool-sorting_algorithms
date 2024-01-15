#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers using the
 *			insertion Sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;

	listint_t *current, *temp;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			temp->next = current->next;
			temp->prev = current;
			current->next = temp;

			if (temp->next != NULL)
				temp->next->prev = temp;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);
		}
	}
}
