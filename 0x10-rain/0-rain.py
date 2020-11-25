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
    for i in range(1, wallsLength - 1):
        leftPeak = 0
        rightPeak = 0
        for L in range(0, i):
            if (walls[L] > leftPeak):
                leftPeak = walls[L]
        for R in range(i, wallsLength):
            if (walls[R] > rightPeak):
                rightPeak = walls[R]
        rainFill = min(leftPeak, rightPeak)
        rainFill = abs(walls[i] - rainFill)
        rainAmount += rainFill
        walls[i] = rainFill
    return (rainAmount)
