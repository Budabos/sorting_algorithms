#include <stdio.h>
int *bubble_sort(int *array, size_t size)
{
	int tmp = 0;
	for (size; size > 0; size--)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[j] > array[j+1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
	return array;

}


int main(void)
{
	int my_array[] = {9, 0, 0, 3, 3, 7, 6, 23, 23, 98, 24, 17, 67, 56};
	int *sorted = bubble_sort(my_array, 13);

	for (int i = 0; i < 14; i++)
	{
		printf("%d\n", sorted[i]);
	}
}