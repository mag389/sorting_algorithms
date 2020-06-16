#include "sort.h"
void swap_forward(listint_t **tmp, listint_t **list);
void print_back(listint_t **head);
void print_backwards(listint_t **head);
/**
* cocktail_sort_list - cocktail sorts the list
* Return: void
* @list: the double linnked list to sort
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1, len = 0, i;
	listint_t *tmp;

	if (list == NULL)
		return;
	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	tmp = *list;
	while (swapped == 1)
	{
		swapped = 0;
		for (len--, i = 0; i < len; i++)
		{
/*			printf("len: %i i: %i\n", len, i);*/
			if (tmp->n > tmp->next->n)
			{
				swap_forward(&tmp, list);
				swapped = 1;
				print_list(*list);
/*				printf("---");*/
/*				print_back(list);*/
			}
			else
				tmp = tmp->next;
		}
		if (swapped == 0)
			return;
		swapped = 0;
		tmp = tmp->prev;
		for (len--, i = 0; i < len; i++)
		{
/*			printf("len: %i i: %i\n", len, i);*/
			if (tmp->n < tmp->prev->n)
			{
/*				printf("the n is %i\n", tmp->n);*/

				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				tmp->next = tmp->prev;
				tmp->prev = tmp->next->prev;
				tmp->next->prev = tmp;
				if (tmp->prev == NULL)
					*list = tmp;
				else
					tmp->prev->next = tmp;

/*				swap_forward(*(tmp->prev), list);*/
				swapped = 1;
				print_list(*list);
/*				printf("---");*/
/*				print_back(list);*/
			}
			else
				tmp = tmp->prev;
		}
		if (swapped == 0)
			return;
		tmp = tmp->next;
	}
}

/**
* swap_forward - swaps dlist node with next
* Return: void
* @list: the list, for if the head changes
* @tmp: the node to swap with it's next
*/
void swap_forward(listint_t **tmp, listint_t **list)
{
	(*tmp)->next->prev = (*tmp)->prev;
	if ((*tmp)->prev)
		(*tmp)->prev->next = (*tmp)->next;
	(*tmp)->prev = (*tmp)->next;
	(*tmp)->next = (*tmp)->next->next;
	if ((*tmp)->next)
		(*tmp)->next->prev = (*tmp);
	(*tmp)->prev->next = (*tmp);
	if ((*tmp)->prev->prev == NULL)
		*list = (*tmp)->prev;
}

/**
* print_back - prints back
* Return: void
* @head: the head node
*/
void print_back(listint_t **head)
{
	if ((*head)->next)
		print_back(&(*head)->next);
	else
		print_backwards(head);
}
/**
* print_backwards - prints back from the tail
* Return: void
* @tail: the tail node
*/
void print_backwards(listint_t **tail)
{
	printf("%i ", (*tail)->n);
	if ((*tail)->prev)
		print_backwards(&(*tail)->prev);
}
