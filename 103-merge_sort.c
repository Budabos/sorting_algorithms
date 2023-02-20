#include "sort.h"


/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @left: The front index of the array.
 * @mid: The middle index of the array.
 * @right: The back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t left, size_t mid,
		size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + left, mid - left);

	printf("[right]: ");
	print_array(subarr + mid, right - mid);

	for (i = left, j = mid; i < mid && j < right; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < right; j++)
		buff[k++] = subarr[j];
	for (i = left, k = 0; i < right; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + left, right - left);
}

/**
 * merge_sort_recursive - merge_sort divide and conquer implementation.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @left: left subarray.
 * @right: right subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(subarr, buff, left, mid);
		merge_sort_recursive(subarr, buff, mid, right);
		merge_subarr(subarr, buff, left, mid, right);
	}
}

/**
 * merge_sort - merge_sort, divides array into left and right and sort
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
