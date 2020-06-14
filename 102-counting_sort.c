#include "sort.h"

void counting_sort(int *array, size_t size)
{
	int *count_array, *final_array, highest, number_in_original_array, j, m;
	size_t i, k;

	if (size < 2)
	{
		print_array(array, size);
		return;
	}

	highest = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > highest)
			highest = array[i];

	count_array = malloc(sizeof(size_t) * (highest + 1));
	final_array = malloc(sizeof(int) * size);
	/*fill array with 0s, from 0-highest number_in_original_arrayber */
	for (j = 0; j <= highest; j++)
		count_array[j] = 0;
	for (k = 0; k < size; k++)
	{
		number_in_original_array = array[k];
		count_array[number_in_original_array] += 1;
	}
	for (m = 1; m <= highest; m++)
		count_array[m] += count_array[m - 1];
	print_array(count_array, highest + 1);
}
