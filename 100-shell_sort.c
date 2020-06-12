#include "sort.h"

/**
 * shell_sort - sorts an array in ascending order using the Shell sort
 * @array: array to ordering
 * @size: size of array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j;
	int middle_of_list = 0;

	if (array == NULL || size < 2)
		return;

	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			middle_of_list = array[i];
			for (j = i; array[j - gap] > middle_of_list; j = j - gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = middle_of_list;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
