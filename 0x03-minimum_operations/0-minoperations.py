#!/usr/bin/python3
""" Calculates the fewest number of operations needed to result in exactly n H characters. """
def minOperations(n):
    copy = "H"
    output = ""
    i = 0
    if (n < 2):
        return 0
    while (len(output) < n):
        if (i % 2 == 0):
            output += copy
        else:
            copy = output
            output += copy
        i += 1
    return i
