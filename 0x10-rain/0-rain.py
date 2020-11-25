#!/usr/bin/python3
"""
Calculate how much water will be retained after it rains.
Wall width is 1
"""


def rain(walls):
    rainAmount = 0
    rainFill = 0
    wallsLength = len(walls)
    if (wallsLength == 0):
        return (0)
    for i in range(wallsLength - 1):
        if (i >= 1 and i < wallsLength - 1):
            if (walls[i - 1] > walls[i]):
                rainFill = abs(walls[i - 1] - walls[i])
                for b in range(i + 1, wallsLength):
                    if (walls[b] > 0):
                        break
                if (rainFill > walls[b]):
                    rainFill = abs(walls[b] - walls[i])
                rainAmount += rainFill
                walls[i] += rainFill
    return (rainAmount)
