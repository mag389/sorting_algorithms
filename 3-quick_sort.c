#include "sort.h"

void quick_sort_rec(int *ar, size_t size, size_t orig, size_t offset);
/**
* quick_sort - quick sorts the array
* Return: void
* @array: the int array to sort
* @size: the size of teh array
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_rec(array, size, size, 0);
}


void quick_sort_rec(int *array, size_t size, size_t orig, size_t offset)
{
	unsigned int i, j;
	int pivot, swap, *left, leftsize;

	print_array(array, size);
	if (size <= 1)
		return;
	left = array;
	leftsize = 0;
	pivot = array[size - 1];
	printf("pivot: %i\n", pivot);
	for (i = 0; i < size; i++)
	{
/*		printf("into loop, i: %i\n", i);*/
		if (array[i] < pivot)
		{
			/*printf("left: %i i: %i\n", leftsize, i);*/
			left++;
			leftsize++;
			continue;
		}
		for (j = i; j < size - i; j++)
		{
			/*printf("-------------");*/
			if (array[j] < array[i] && array[j] <= pivot)
			{
				printf("i: %i j: %i\n", i, j); 
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				left++;
				leftsize++;
				print_array((array - offset), orig);
			printf("the pviot is %i size: %i off%i\n", pivot,(int) orig, (int) offset);
			}
		}
		
	}
	quick_sort_rec(array, leftsize, orig, 0 + offset);
	quick_sort_rec(left++, size - leftsize, orig, leftsize + offset);
}
