#include "sort.h"
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, lowest, value_of_array_at_i;
	for (i = 0; i < size; i++)
	{
		lowest = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[lowest])
				lowest = j;
		}
		value_of_array_at_i = array[i];
		array[i] = array[lowest];
		array[lowest] = value_of_array_at_i;
		if (i != lowest)
			print_array(array, size);
	}
}
