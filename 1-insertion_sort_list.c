#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list.
 * @list: A pointer to a pointer to the head of the doubly linked list.
 * @node1: Pointer to the first node to swap.
 * @node2: Pointer to the second node to swap.
 */

void swap(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers using the
 *			insertion Sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{
			swap(list, &temp, current);
			print_list(*list);
		}
	}
}
