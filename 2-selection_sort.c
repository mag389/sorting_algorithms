#include "sort.h"

/**
* selection_sort - sorts array via selection algorithm
* Return: Void
* @array: the int array to sort
* @size: the size of the array
*/
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, current_min = 0;
	int tmp;

	for (i = 0; i < size; i++)
	{
		current_min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[current_min])
				current_min = j;
		}
		if (current_min != i)
		{
			tmp = array[i];
			array[i] = array[current_min];
			array[current_min] = tmp;
			print_array(array, size);
		}
	}
}
