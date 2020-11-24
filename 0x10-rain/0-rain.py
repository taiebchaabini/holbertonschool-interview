#!/usr/bin/python3
"""
Calculate how much water will be retained after it rains.
Wall width is 1
"""


def rain(walls):
    i = 0
    rainAmount = 0
    if (len(walls) == 0):
        return (0)
    for element in walls:
        i += 1
        if (i > 0 and i < len(walls) - 1):
            if (abs(walls[i - 1] - walls[i + 1]) > walls[i]):
                if (walls[i - 1] < walls[i + 1]):
                    rainAmount += walls[i - 1]
                elif(walls[i - 1] > walls[i + 1]):
                    rainAmount += walls[i + 1]
    return (rainAmount)
