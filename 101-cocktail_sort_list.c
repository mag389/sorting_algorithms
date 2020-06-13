#include "sort.h"
void swap_forward(listint_t *list);
/**
* cocktail_sort_list - cocktail sorts the list
* Return: void
* @list: the double linnked list to sort
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1, len = 0, i;
	listint_t *tmp = *list;

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
				swap_forward(tmp);
/*
*				tmp->next->prev = tmp->prev;
*				if (tmp->prev)
*					tmp->prev->next = tmp->next;
*				tmp->prev = tmp->next;
*				tmp->next = tmp->prev->next;
*				tmp->prev->next = tmp;
*				if (tmp->next)
*					tmp->next->prev = tmp;
*/
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
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
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
		tmp = tmp->next;
	}
}

/**
* swap_forward - swaps dlist node with next
* Return: void
* @tmp: the node to swap with it's next
*/
void swap_forward(listint_t *tmp)
{
	tmp->next->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	tmp->prev = tmp->next;
	tmp->next = tmp->prev->next;
	tmp->prev->next = tmp;
	if (tmp->next)
		tmp->next->prev = tmp;
}
