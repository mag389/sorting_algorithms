#include "sort.h"
/**
 * list_length - returns the length of a linked list
 * @h: the list
 *
 * Return: length of list
 */
int list_length(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}
/**
 * insertion_sort_list- sorts a list using insertion method
 * @list: pointer to the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	node = (*list)->next;

	if (!list || !*list)
		return;
	if (list_length(*list) < 2)
	{
		print_list(*list);
		return;
	}

	while (node)
	{
		while ((node->prev != NULL) && (node->prev->n > node->n))
		{
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;

			node->next = node->prev;
			node->prev = node->prev->prev;
			node->next->prev = node;

			if (node->prev == NULL)
			{
				*list = node;
			}
			else
			{
				node->prev->next = node;
			}
			print_list(*list);
		}

		node = node->next;
	}
}
