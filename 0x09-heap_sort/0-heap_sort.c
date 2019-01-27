#include "sort.h"

/**
 * siftdown - sift top node of a heap down
 * @array: array to sift
 * @start: which node to start at
 * @end: end of the array
 * @size: max array size
 * Return: void
 */
void siftdown(int *array, size_t start, size_t end)
{
	size_t x = start, left, right;
	int temp = 0;

	while (x < end)
	{
		left = x * 2 + 1;
		right = x * 2 + 2;
		if (left <= end)
		{
			if (right <= end)
			{
				if (array[left] > array[right])
				{
					if (array[left] > array[x])
					{
						temp = array[x];
						array[x] = array[left];
						array[left] = temp;
						x = left;
					}
					else
					{
						break;
					}
				}
				else
				{
					if (array[right] > array[x])
					{
						temp = array[x];
						array[x] = array[right];
						array[right] = temp;
						x = right;
					}
					else
					{
						break;
					}
				}
			}
			else
				if (array[left] > array[x])
				{
					temp = array[x];
					array[x] = array[left];
					array[left] = temp;
					x = left;
				}
				else
				{
					break;
				}
		}
		else
		{
			x = end;
		}
	}
}

/**
 * heapify - Creates a max heap out of an array
 * @array: array to heapify
 * @size: length of the array
 * Return: void
 */
void heapify(int *array, size_t size)
{
	int start = size - 1;

	while (start >= 0)
	{
		siftdown(array, start, size - 1);
		start--;
	}
}

/**
 * heap_sort - sorts an array using heap sort method
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int end = size - 1, start = 0, temp;

	if (size > 1)
	{
		heapify(array, size);
		while (end > 0)
		{
			siftdown(array, start, end);
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			print_array(array, size);
			end--;
		}
	}
}
