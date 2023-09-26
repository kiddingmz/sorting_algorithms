#include "sort.h"

/**
 * swap_int - swap two integers in an array
 *
 * @a: The first integer to swap
 * @b: The second integer to swap
 *
 * Return: nothing
 */

void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - turn a binary tree into a complete binary heap
 *
 * @array: An array of integers representing a binary tree
 * @size: The size of the array/tree
 * @base: The index of the base row of the tree
 * @root: The root node of the binary tree
 *
 * Return: nothing
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_int(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - heap sort algorithm
 *
 * @array: an array of integers
 * @size: the size of the array
 *
 * Return: nothing
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_int(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
