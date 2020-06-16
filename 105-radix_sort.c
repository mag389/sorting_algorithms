#include "sort.h"
void radix_sort_r(int *array, size_t size, int step);
/**
* radix_sort - sorts array by radix algo
* Return: void
* @array: the array to sort
* @size: the size of the array
*/
void radix_sort(int *array, size_t size)
{
	if (!array)
		return;
	radix_sort_r(array, size, 1);
}

/**
* radix_sort_r - radix sorts array recursive call
* Return: void
* @array: the array to sort
* @size: the size of the array
* @step: what level digit to use
*/
void radix_sort_r(int *array, size_t size, int step)
{
	int *work, i, j, workindex = 0, w = 0, digit = 0;

/*	if (step > 1000)		return;*/
/*	printf("size is: %i  step: %i\n", (int)size, step);*/
	work = malloc(size * sizeof(int));
	if (work == NULL)
		return;
	for (j = 0; j < 10; j++)
	{
		if (array[i] / step >= 10)
			digit = 1;
		for (i = 0; i < (int)size; i++)
		{
/*			printf("number: %i, reduced: %i == %i\n",*/
/*			array[i], array[i] / step % 10, j);*/
			if ((array[i] / step) % 10 == j)
			{
/*				printf("in the if %i\n", array[i]);*/
				work[workindex] = array[i];
/*				printf("work[worki]: %i\n", work[workindex]);*/
				workindex++;
			}
		}
	}
/*	printf("workindex: %i\n", workindex);*/
	for (i = 0; i < (int)size; i++)
		if (array[i] != work[i])
			array[i] = work[i], w = 1;
/*	print_array(work, size);*/
	free(work);
	if (w != 0 || digit != 0)
	{
		print_array(array, size);
		radix_sort_r(array, size, step * 10);
	}
}
