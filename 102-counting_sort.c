#include <string.h>
#include "sort.h"

/**
 * find_max_element - finds the maximum element in the array.
 * @array: elements in the array
 * @size: size of the array
 * Return: maximum number.
 */
size_t find_max_element(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * create_count_array - creates the counted array.
 * @size: size of the array.
 * Return: counted array
 */
int *create_count_array(size_t size)
{
	int *count_array = malloc(sizeof(int) * (size + 1));

	if (count_array == NULL)
		return (NULL);
	memset(count_array, 0, sizeof(int) * (size + 1));
	return (count_array);
}

/**
 * count_occurrences - counts the number of times a number appears.
 * @array: has the elements.
 * @size: size of the elements.
 * @count_array: counted array of elements.
 */
void count_occurrences(int *array, size_t size, int *count_array)
{
	size_t i;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;
}

/**
 * counting_sort - counts the individual elements with the counted array.
 * @array: array of elements.
 * @size: size of the elements.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output;
	size_t i, max = 0;

	max = find_max_element(array, size);
	count_array = create_count_array(max);
	if (count_array == NULL)
		return;
	count_occurrences(array, size, count_array);
	print_array(count_array, max + 1);
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		output[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	memcpy(array, output, sizeof(int) * size);

	free(count_array);
	free(output);
}
