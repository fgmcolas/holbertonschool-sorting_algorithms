#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using the
 *		selection Sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, minindex;

	for (i = 0; i < size - 1; i++)
	{
		minindex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minindex])
				minindex = j;
		}

		if (minindex != i)
		{
			temp = array[i];
			array[i] = array[minindex];
			array[minindex] = temp;
			print_array(array, size);
		}
	}
}
