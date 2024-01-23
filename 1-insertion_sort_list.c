#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @point1: A pointer to the first node to swap.
 * @point2: The second node to swap.
 */
void swap_nodes(listint_t **head, listint_t **point1, listint_t *point2)
{
	(*point1)->next = point2->next;
	if (point2->next != NULL)
		point2->next->prev = *point1;
	point2->prev = (*point1)->prev;
	point2->next = *point1;
	if ((*point1)->prev != NULL)
		(*point1)->prev->next = point2;
	else
		*head = point2;
	(*point1)->prev = point2;
	*point1 = point2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
