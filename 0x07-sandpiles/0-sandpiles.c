#include "sandpiles.h"

/**
 * print_grid - prints a grid
 * @grid: grid to print
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Sums 2 sandpiles into grid 1
 * @grid1: first grid. Sum will be in this grid.
 * @grid2: second grid to add to grid1
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int stable = 0;
	int i, j;

	while (!stable) {
		stable = 1;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				grid1[i][j] = grid1[i][j] + grid2[i][j];
				grid2[i][j] = 0;
				if (grid1[i][j] > 3) {
					stable = 0;
				}
			}
		}
		if (!stable){
			printf("=\n");
			print_grid(grid1);
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					if (grid1[i][j] > 3) {
						grid1[i][j] -= 4;
						if (i - 1 >= 0) {
							grid2[i - 1][j] += 1;
						}
						if (i + 1 < 3) {
							grid2[i + 1][j] += 1;
						}
						if (j - 1 >= 0) {
							grid2[i][j - 1] += 1;
						}
						if (j + 1 < 3) {
							grid2[i][j + 1] += 1;
						}
					}
				}
			}
		}
	}
}
