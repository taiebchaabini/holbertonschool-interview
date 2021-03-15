#!/usr/bin/python3
""" Finds the perimeter of the island """


def island_perimeter(grid):
    """ Finds the perimeter of the island """
    cSum = 0
    for y in range(len(grid)):
        for x in range(len(grid[y])):
            if (grid[y][x] != 0):
                cSum += 4
                if (x + 1 <= len(grid[y]) - 1 and grid[y][x + 1] != 0):
                    cSum -= 1
                if (x - 1 >= 0 and grid[y][x - 1] != 0):
                    cSum -= 1
                if (y - 1 >= 0 and grid[y - 1][x] != 0):
                    cSum -= 1
                if (y + 1 <= len(grid) - 1 and grid[y + 1][x] != 0):
                    cSum -= 1
    return cSum
