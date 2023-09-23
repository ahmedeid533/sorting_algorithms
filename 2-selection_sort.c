#include "sort.h"

/**
 * selection_sort - selection sort
 *
 * @array: The list to be sorted
 * @size: the array size
 */
void selection_sort(int *array, size_t size)
{
	int i;
	int smallest_index;
	int j;

	for (i = 0; i < size; i++)
	{
		smallest_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_index])
			{
				smallest_index = j;
			}
			swap(&array[i], &array[smallest_index]);
		}
	}
}
