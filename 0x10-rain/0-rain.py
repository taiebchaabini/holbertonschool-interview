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
        if (i != len(walls)):
            rainAmount += element
    return (rainAmount)
