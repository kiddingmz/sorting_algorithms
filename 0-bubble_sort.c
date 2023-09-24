#include "sort.h"

/**
 * bubble_sort - sorts an array
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp_size;
	int tmp, _bool;

	tmp_size = size;
	_bool = 0;
	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < tmp_size; j++)
		{
			if (array[j - 1] > array[j])
			{
				_bool = 1;
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				print_array(array, size);
			}
		}
		if (_bool == 0)
			break;
		_bool = 0;
		tmp_size--;
	}
}
