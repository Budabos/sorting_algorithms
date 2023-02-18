#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, tmp_size;
	int tmp;


	bool swaped = false;

	tmp_size = size;

	if (array == NULL || size < 2)
		return;

	while (!swaped)
	{
		swaped = true;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, tmp_size);
				swaped = false;

			}
		}
		size--;
	}
}
