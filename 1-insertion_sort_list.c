#include "sort.h"
/**
 * list_length- returns the length of list
 * @head: pointer to the list
 *
 * Return: length of list
 */
int list_length(listint_t *head)
{
	int len = 0;

	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return (len);
}
/**
 * insertion_sort_list - sorts a linked list
 * @list: pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *temp_one, *temp_two, *temp_three, *temp_four;

	if (!list || !*list)
		return;
	if (list_length(*list) < 2)
	{
		print_list(*list);
		return;
	}
	while (list)
	{
		while (current->next && current->n < current->next->n)
			current = current->next;
		if (!current->next)
			return;
		temp_one = current->prev;
		temp_two = current;
		temp_three = current->next;
		temp_four = current->next->next;
		temp_two->next = temp_four;
		if (temp_four)
			temp_four->prev = temp_two;
		temp_three->next = temp_two;
		temp_three->prev = temp_two->prev;
		if (temp_one)
			temp_one->next = temp_three;
		else
			*list = temp_three;
		temp_two->prev = temp_three;
		current = *list;
		print_list(current);
	}
}
