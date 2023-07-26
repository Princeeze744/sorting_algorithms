#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using quick sort
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 1)
		return;

	_quick_sort(&array, size, 0, size - 1);
}

/**
 * _quick_sort - internal working quick sort function
 * @array: array to be sorted
 * @size: size of the array
 * @left: lower bound of the array
 * @right: upper bound of the array
 */
void _quick_sort(int **array, size_t size, int left, int right)
{
	int pivot_idx, *arr;

	if (left > right)
		return;

	arr = *array;
	pivot_idx = partition(&arr, size, left, right);
	/*if ((pivot_idx - 1) - left > 1)*/
	_quick_sort(&arr, size, left, pivot_idx - 1);
	/*if (right - (pivot_idx + 1) > 1)*/
	_quick_sort(&arr, size, pivot_idx + 1, right);
}

/**
 * partition - partitions the array around the chosen pivot
 * @array: array to be partitioned
 * @size: size of the array
 * @left: lower bound
 * @right: upper bound
 * Return: returns the final position of the pivot
 */
int partition(int **array, size_t size, int left, int right)
{
	int *arr, pivot, i, j;

	if ((right - left) < 1)
		return (left);

	arr = *array;
	pivot = arr[right];
	i = left - 1;
	for (j = left; j <= right - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i == j)
				continue;
			swap_arr(&arr, i, j);
			print_array(arr, size);
		}
	}
	if ((i + 1) == right)
		return (i + 1);

	swap_arr(&arr, i + 1, right);
	print_array(arr, size);
	return (i + 1);
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
