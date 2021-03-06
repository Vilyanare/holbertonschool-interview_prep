#include "slide_line.h"

/**
 * slide_line - Slide and merge an array of ints
 * @line: Array to slide
 * @size: Size of the array
 * @direction: Direction in which to slide the array
 * Return: 0 on failure otherwise 1
 */
int slide_line(int *line, size_t size, int direction)
{
	int hold, x, increase, stop;

	if (size < 2)
		return(1);

	if (direction == SLIDE_RIGHT)
	{
		x = size - 2;
		hold = size - 1;
		stop = -1;
		increase = -1;
	}
	else if (direction == SLIDE_LEFT)
	{
		x = 1;
		hold = 0;
		stop = size;
		increase = 1;
	}
	for (; x != stop; x += increase)
		if (line[x] != 0)
		{
			if (line[x] == line[hold])
			{
				line[x] = 0;
				line[hold] *= 2;
				hold += increase;
			}
			else if (line[hold] == 0)
			{
				line[hold] = line[x];
				line[x] = 0;
			}
			else
				hold += increase;
			if (x + increase == stop && line[x] != 0 && line[hold] == 0)
			{
				line[hold] = line[x];
				line[x] = 0;
			}
		}
	return(1);
}
