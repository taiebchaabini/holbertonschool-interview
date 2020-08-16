#ifndef sandpiles_h
#define sandpiles_h
#include <stdio.h>
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
int sandpiles_check(int grid1[3][3]);
void sandpiles_compute(int (*grid1)[3], int grid2[3][3]);
void sandpiles_toppling(int (*grid1)[3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
#endif