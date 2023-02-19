#include "sort.h"

/**
 * selection_sort - a function that sort a list with the
 *                  selection algorith
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int lowest;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		lowest = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (lowest > array[j])
			{
				lowest = array[j];
				index = j;
			}
		}
		if (i != index)
		{
			array[index] = array[i];
			array[i] = lowest;

			print_array(array, size);
		}
	}
}
