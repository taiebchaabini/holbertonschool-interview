#!/usr/bin/python3
"""
Returns a list of lists of integers representing the Pascal’s triangle of n
"""


def pascal_triangle(n):
    myList = [[1]]
    if (n <= 0):
        return [[]]
    for i in range(1, n):
        myList.append([1])
        for b in range(1, i):
            tmp = int(myList[i - 1][b]) + int(myList[i - 1][b - 1])
            myList[i].append(str(tmp))
        myList[i].append(1)
    return myList
