#include "sort.h"
/**
 * merge_sort - accepts array and sorts it
 * @array: array to sort
 * @size: size of array to sort
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *array_copy = malloc(size * sizeof(int));

	copy_array(array, 0, size, array_copy);
	top_down_split(array_copy, 0, size, array);
	free(array_copy);
}

/**
 * copy_array - copyies the main array into a working version
 * @array: source array
 * @start_index: what it says on the tin
 * @end_index: what it says on the tin
 * @array2: blank array to copy source into
 *
 * Return: copied array
 */
int  copy_array(int *array, int start_index, int end_index, int *array2)
{
	int i;

	for (i = start_index; i < end_index; i++)
	{
		array2[i] = array[i];
	}
	return (*array2);
}

/**
 * top_down_split - splits the array in half to sort
 * @array2: copy of the the source array
 * @start_index: first index of array2
 * @end_index: size of array2
 * @array3: secondary array used in the spliting in half
 *
 * Return: Void
 */
void top_down_split(int *array2, int start_index, int end_index, int *array3)
{
	int center_index;

	center_index = (start_index + end_index) / 2;
	if (end_index - start_index <= 1)
		return;
	top_down_split(array2, start_index, center_index, array3);
	top_down_split(array2, center_index, end_index, array3);
	top_down(array3, start_index, center_index, end_index, array2);
}

/**
 * top_down - merges split arrays back into 1 array
 * @array: sources to merge
 * @start: first endex
 * @center: center of array
 * @end: last index
 * @array2:  result of merge
 *
 * Return: void
 */
void top_down(int *array, int start, int center, int end, int *array2)
{
	int i;

	for (i = start; i < end; i++)
	{
		if (start < center && (center >= end || array[start] <= array[center]))
		{
			array2[i] = array[start];
			start += 1;
		}
		else
		{
			array2[i] = array[center];
			center += 1;
		}
	}
}
