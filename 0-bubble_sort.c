#include "sort.h"

/**
 * bubble_sort - bubble sort
 *
 * @array: The list to be sorted
 * @size: the array size
 */

void bubble_sort(int *array, size_t size)
{
	int i;
	int j;
	int temp;

	for (i = size - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (array [j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
