#include "sort.h"

void quick_sort_hrec(int *ar, size_t size, size_t orig, size_t offset);
/**
* quick_sort_hoare - quick sorts the array
* Return: void
* @array: the int array to sort
* @size: the size of teh array
*/
void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_hrec(array, size, size, 0);
}

/**
* quick_sort_hrec - quick sorts the array, the recursive function
* Return: void
* @array: the array to sort (or subarray)
* @size: size of the current array being sorted
* @orig: the original size of the array being sorted
* @offset: the positional offset of the subarray in the original array
*/
void quick_sort_hrec(int *array, size_t size, size_t orig, size_t offset)
{
	int pivot, swap, left, right;

/*	print_array(array - offset, orig);*/
	if (size <= 1 || !array)
		return;
	left = 0;
	right = size - 1;
	pivot = array[size - 1];
/*
*	printf("pivot: %i size: %i\n", pivot,(int) size);
*	print_array(array, size);
*/
	while (1)
	{
		if (array[left] < pivot)
		{
			left++;
			continue;
		}
		if (array[right] > pivot)
		{
			right--;
			continue;
		}
		if (left >= right)
			break;
		swap = array[left];
		array[left] = array[right];
		array[right] = swap;
		left++;
		if (right != (int)size - 1)
			right--;
/*
*		printf("innerprint array: ");
*		printf("left: %i, %i,  num:%i,r num %i -- %i\n",
*left, right, array[right], array[left], pivot);
*/
		print_array((array - offset), orig);
	}
/*	printf("left: %i, right: %i\n", left, right);*/
/*
*	if (left == right && array[left] <= pivot)
*		left++;
*/
/*
*	if (right == left && size == 3)
*		left += 1;
*/
/*
*	printf("leftarray:");
*	print_array(array, left);
*/
	quick_sort_hrec(array, left, orig, 0 + offset);
/*
*	printf("rightarray:");
*	print_array(&array[left], size - left);
*/
	quick_sort_hrec(&array[left], size - left, orig, left + offset);
}
