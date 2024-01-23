#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @i: The first integer to swap.
 * @j: The second integer to swap.
 */
void swap_ints(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @arr: The array of integers.
 * @size: The size of the array.
 * @l: The starting index of the subset to order.
 * @r: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *arr, size_t size, int l, int r)
{
	int *piv, abv, bel;

	piv = arr + r;
	for (abv = bel = l; bel < r; bel++)
	{
		if (arr[bel] < *piv)
		{
			if (abv < bel)
			{
				swap_ints(arr + bel, arr + abv);
				print_array(arr, size);
			}
			abv++;
		}
	}

	if (arr[abv] > *piv)
	{
		swap_ints(arr + abv, piv);
		print_array(arr, size);
	}

	return (abv);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 * @l: The starting index of the array partition to order.
 * @r: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *arr, size_t size, int l, int r)
{
	int a;

	if (r - l > 0)
	{
		a = lomuto_partition(arr, size, l, r);
		lomuto_sort(arr, size, l, a - 1);
		lomuto_sort(arr, size, a + 1, r);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *arr, size_t size)
{
	if (arr == NULL || size < 2)
		return;

	lomuto_sort(arr, size, 0, size - 1);
}
