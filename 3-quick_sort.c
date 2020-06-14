#include "sort.h"
#include <time.h>
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

/**
* quick_sort_rec - the actual quicksort
* Return: void
* @array: the array to sort
* @size: size of the array
* @orig: the original array for printing
* @offset: how far the right the array is from the original array
*/
void quick_sort_rec(int *array, size_t size, size_t orig, size_t offset)
{
	int pivot, swap, left, right;

/*	print_array(array - offset, orig);*/
	if (size <= 1)
		return;
/*	print_array(array, size);*/
	left = 0;
	right = left + 1;
	pivot = array[size - 1];
/*	printf("pivot: %i size: %i\n", pivot,(int) size);*/
	while (left < (int) size)
	{
		if (array[left] < pivot)
		{
			left++;
			right++;
			continue;
		}
		if (right >= (int)size - 1)
		{
			/*right = left + 1;*/
			break;
		}
		if (array[right] > pivot)
		{
			right++;
			continue;
		}
		else
		{
			swap = array[left];
			array[left] = array[right];
			array[right] = swap;
			left++;
			right = left + 1;
/*			printf("innerprint array: \n");*/
/*			print_array(array, size);*/
			print_array((array - offset), orig);
		}
	}
/*	printf("left: %i, right: %i\n", left, right);*/
/*	if (left != (int) size - 1)*/
	if (right == (int) size - 1)
	{
		swap = array[left];
/*		printf("swap is: %i\n", swap);*/
		array[left] = array[size - 1];
		array[size - 1] = swap;
		print_array((array - offset), orig);
	}
	quick_sort_rec(array, left, orig, 0 + offset);
	quick_sort_rec(&array[left + 1], size - left - 1, orig, 1 + left + offset);
}
