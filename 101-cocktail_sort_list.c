#include "sort.h"

/**
 * swap_ahead - Swap a node in a list with the node ahead of it
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @now: A pointer to the current swapping node.
 */
void swap_ahead(listint_t **list, listint_t **tail, listint_t **now)
{
	listint_t *temp = (*now)->next;

	if ((*now)->prev != NULL)
		(*now)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*now)->prev;
	(*now)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *now;
	else
		*tail = *now;
	(*now)->prev = temp;
	temp->next = *now;
	*now = temp;
}

/**
 * swap_behind - Swap a node in a list with the node behind it.
 * @list: A pointer to the head of a doubly-linked list.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @now: A pointer to the current swapping node.
 */
void swap_behind(listint_t **list, listint_t **tail, listint_t **now)
{
	listint_t *temp = (*now)->prev;

	if ((*now)->next != NULL)
		(*now)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*now)->next;
	(*now)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *now;
	else
		*list = *now;
	(*now)->next = temp;
	temp->prev = *now;
	*now = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *now;
	bool shaken = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken == false)
	{
		shaken = true;
		for (now = *list; now != tail; now = now->next)
		{
			if (now->n > now->next->n)
			{
				swap_ahead(list, &tail, &now);
				print_list((const listint_t *)*list);
				shaken = false;
			}
		}
		for (now = now->prev; now != *list;
				now = now->prev)
		{
			if (now->n < now->prev->n)
			{
				swap_behind(list, &tail, &now);
				print_list((const listint_t *)*list);
				shaken = false;
			}
		}
	}
}
