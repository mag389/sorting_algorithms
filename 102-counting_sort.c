#include "sort.h"

void counting_sort(int *array, size_t size)
{
	int *count_array, *final_array, highest, lowest, number_in_original_array, j, find_numbers;
	int count;
	size_t i;

	if (size < 2)
	{
		print_array(array, size);
		return;
	}

	highest = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > highest)
			highest = array[i];
	lowest = array[0];

	for (i = 1; i < size; i++)
		if (array[i] < lowest)
			lowest = array[i];

	count_array = malloc(sizeof(size_t) * (highest + 1));
	final_array = malloc(sizeof(int) * size);
	/*fill array with 0s, from 0-highest number_in_original_arrayber */
	for (j = 0; j <= highest; j++)
		count_array[j] = 0;
	for (i = 0; i < size; i++)
	{
		number_in_original_array = array[i];
		count_array[number_in_original_array] += 1;
	}
	for (j = 1; j <= highest; j++)
		count_array[j] += count_array[j - 1];
	print_array(count_array, highest + 1);
	count = 0;
	for (i = 0; i < size; i++)
	{
		final_array[count_array[array[i]] - 1] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = final_array[i];
	free(final_array);
	free(count_array);
}
