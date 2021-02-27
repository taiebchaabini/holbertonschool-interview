#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the
fewest number of coins needed to meet a given amount total.
"""


def makeChange(coins, total):
    if (total <= 0):
        return (-1)
    coins = reversed(sorted(coins))
    opSum = 0
    hit = total
    for i in coins:
        opSum += int(total / i)
        total -= int(total / i) * i
        if (hit == 0):
            return (opSum)
        if (hit < 0):
            return (-1)
    return (-1)
