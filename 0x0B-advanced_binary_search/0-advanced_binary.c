#include "search_algos.h"

void print_array(int *array, size_t size)
{
	int first = 1;
	size_t x = 0;

	printf("Searching in array: ");

	for (x = 0; x < size; x++)
	{
		if (first == 0)
		{
			printf(", ");
		}
		printf("%d", array[x]);
		first = 0;
	}
	printf("\n");
}
/**
 * advanced_binary - Searchs for the lowest index of matched value
 * @array: array to search
 * @size: size of the array
 * @value: value to search for
 * Return: lowest matching index of value or -1 on error
 */
int advanced_binary(int *array, size_t size, int value)
{
	int half = (size - 1) / 2, hold = 0;

	if (size == 0 || array == NULL)
	{
		return (-1);
	}
	if (size == 1 && array[0] != value)
	{
		return (-1);
	}
		print_array(array, size);

	if (array[half] == value)
	{
		if (array[half - 1] == value)
		{
			return (advanced_binary(array, size / 2, value));
		}
		else
		{
			return half;
		}
	}

	if (array[half] > value)
	{
		return (advanced_binary(array, half, value));
	}
	else
	{
		hold = advanced_binary(array + size / 2 + size % 2, size / 2, value);
		if (hold == -1)
			return (-1);
		else
			return (hold + size / 2 + size % 2);
	}

	return (-1);
}
