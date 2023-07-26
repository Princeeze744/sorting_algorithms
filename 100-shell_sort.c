#include "sort.h"
#include <stdio.h>
/**
  * shell_sort - shell sort, knuth sequence
  * @array: array to be sorted
  * @size: size of array
  */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	gap = 1;
	while (gap < size)
		gap = (gap * 3) + 1;
	printf("gap: %ld\n", gap);
	gap = (gap - 1) / 3;
	printf("gap before loop: %ld\n", gap);
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			printf("i: %ld\n", i);
			tmp = array[i];
			printf("comparing %d and %d\n", array[i - gap], tmp);
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				printf("j: %ld\n", j);
				printf("compared: %d > %d\n", array[j - gap], tmp);
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

