#include "menger.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * check_x_y - checks x y coord to see if it is filled in or not
 * @x: x coord
 * @y: y coord
 * Return: 1 for filled 0 for not
 */
int check_x_y(int x, int y)
{
	while (x > 0 && y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

/**
 * print_array - print a 2d array
 * @arr: Array to print
 * @size: size of array
 * Return: Void
 */
void print_array(int *arr, int size)
{
	int x, y, c = sqrt(size);

	for (x = 0; x < c; x++)
		for (y = 0; y < c; y++)
		{
			if (*(arr + (x * c) + y) == 1)
				printf("#");
			else
				printf(" ");
			if (y == c - 1)
				printf("\n");
		}
}

/**
 * menger - Creates a 2d representation of a menger sponge
 * @level: How many levels you want the menger sponge to go to
 * Return: Void
 */
void menger(int level)
{
	int *arr = NULL;
	int x = 0, y = 0, c = 0;
	double size;

	if (level < 0)
		return;

	if (level == 0)
	{
		printf("#\n");
		return;
	}

	size = pow(9, level);
	c = sqrt(size);
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return;

	for (x = 0; x < c; x++)
		for (y = 0; y < c; y++)
			*(arr + (x * c) + y) = check_x_y(x, y);

	print_array(arr, size);
	free(arr);
}
