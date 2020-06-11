#include "sort.h"

/**
* bubble_sort - implementation of the bubble sort algo
* Return: void
* @array: the int array to sort
* @size: the size of the array
*/
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

}
