#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme for quicksort.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: to print array
 * Return: The final index of the pivot element.
 */
int partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
		print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: to print array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * quicksort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
