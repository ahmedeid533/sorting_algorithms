#include "sort.h"

/**
 * selection_sort - selection sort
 *
 * @array: The list to be sorted
 * @size: the array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t smallest_index;
	size_t j;
	int temp;

	for (i = 0; i < size; i++)
	{
		smallest_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_index])
			{
				smallest_index = j;
			}
		}
		if (i != smallest_index)
		{
			temp = array[i];
			array[i] = array[smallest_index];
			array[smallest_index] = temp;
			print_array(array, size);
		}
	}
}
