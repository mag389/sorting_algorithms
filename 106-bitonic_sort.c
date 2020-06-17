#include "sort.h"
void bitonic_sort_r(int *array, size_t size, int orig, int up);
void bitonic_merge(int *array, size_t size, int up);
/**
* bitonic_sort - calls the bitonic sort function
* Return: void
* @array: the array to sort
* @size: size of the array
*/
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_r(array, size, size, 1);
}
/**
* bitonic_sort_r - sorts array bitonic algo, recursive funciton
* Return: void
* @array:array to sort
* @size: size to sort
* @orig: original size for printing
* @up: whther it's sorting ascending or descending
*/
void bitonic_sort_r(int *array, size_t size, int orig, int up)
{
	if (size <= 1)
		return;
	if (up == 1)
		printf("Merging [%i/%i] (UP):\n", (int)size, orig);
	else
		printf("Merging [%i/%i] (DOWN):\n", (int)size, orig);
	print_array(array, size);

	bitonic_sort_r(array, size / 2, orig, 1);
	bitonic_sort_r(&(*(array + size / 2)), size - size / 2, orig, 0);
	bitonic_merge(array, size, up);
	printf("Result [%i/%i] (", (int)size, orig);
	if (up == 1)
		printf("UP):\n");
	else
		printf("DOWN):\n");
	print_array(array, size);
}
/**
* bitonic_merge - merges halves of a biton sorted array
* Return: void
* @array: array to merge
* @size:size of the array
* @up: direction to sort 1 for ascending
*/
void bitonic_merge(int *array, size_t size, int up)
{
	int diff, i, swap;

	diff = size / 2;
	if (size <= 1)
		return;
	for (i = 0; i < diff; i++)
		if (up == (array[i] > array[i + diff]))
		{
			swap = array[i];
			array[i] = array[i + diff];
			array[i + diff] = swap;
		}
	bitonic_merge(array, size / 2, up);
	bitonic_merge(&(*(array + diff)), size - diff, up);
}
