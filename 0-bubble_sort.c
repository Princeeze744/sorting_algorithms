#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j;
	int is_sorted;

	if (array == NULL)
		return;

	if (size > 1)
	{
		is_sorted = 0;
		while (!is_sorted)
		{
			is_sorted = 1;
			for (j = 0; j < size - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap_arr(&array, j, j + 1);
					is_sorted = 0;
					print_array(array, size);
				}
			}
		}
	}
}

/**
 * swap_arr - utility function to swap 2 array elements
 * @arr: pointer to the array to be swapped
 * @idx1: first index
 * @idx2: second index
 */
void swap_arr(int **arr, size_t idx1, size_t idx2)
{
	int temp, *array;

	array = *arr;
	temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}
