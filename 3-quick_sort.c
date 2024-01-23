#include "sort.h"

/**
 * swp - Swap two integers in an array.
 * @i: The first integer to swap.
 * @j: The second integer to swap.
 */
void swp(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * part - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @arr: The array of integers.
 * @size: The size of the array.
 * @l: The starting index of the subset to order.
 * @r: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int part(int *arr, size_t size, int l, int r)
{
	int *piv, abv, bel;

	piv = arr + r;
	for (abv = bel = l; bel < r; bel++)
	{
		if (arr[bel] < *piv)
		{
			if (abv < bel)
			{
				swp(arr + bel, arr + abv);
				print_array(arr, size);
			}
			abv++;
		}
	}

	if (arr[abv] > *piv)
	{
		swp(arr + abv, piv);
		print_array(arr, size);
	}

	return (abv);
}

/**
 * srt - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 * @l: The starting index of the array partition to order.
 * @r: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void srt(int *arr, size_t size, int l, int r)
{
	int a;

	if (r - l > 0)
	{
		a = part(arr, size, l, r);
		srt(arr, size, l, a - 1);
		srt(arr, size, a + 1, r);
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

	srt(arr, size, 0, size - 1);
}
