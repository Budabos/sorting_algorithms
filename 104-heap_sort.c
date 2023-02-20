#include "sort.h"

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @index: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size,  size_t base, size_t index)
{
	size_t left, right, large;
	int tmp;

	left = 2 * index + 1;
	right = 2 * index + 2;
	large = index;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;
	if (large != index)
	{
		tmp = array[index];
		array[index] = array[large];
		array[large] = tmp;
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Implements the sift-down heap sort
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (array == NULL || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);
	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
