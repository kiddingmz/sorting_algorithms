#include "sort.h"

/**
 * swap_ints - swap two integers in an array
 *
 * @a: the first integer to swap
 * @b: the second integer to swap
 *
 * Return: nothing
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - sort a bit-onic sequence inside an array of integers
 *
 * @array: an array of integers
 * @size: the size of the array
 * @start: the starting index of the sequence in array to sort
 * @seq: the size of the sequence to sort
 * @flow: the direction to sort in
 *
 * Return: nothing
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - convert an array of integers into a bitonic sequence
 *
 * @array: an array of integers
 * @size: the size of the array
 * @start: the starting index of a block of the building bitonic sequence
 * @seq: the size of a block of the building bitonic sequence
 * @flow: the direction to sort the bitonic sequence block in
 *
 * Return: nothing
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - bitonic sort algorithm
 *
 * @array: an array of integers
 * @size: the size of the array
 *
 * Return: nothing
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
