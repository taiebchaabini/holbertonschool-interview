#!/usr/bin/python3
""" Rotates en 2D matrix in place clockwise """


def rotate_2d_matrix(m):
    LEN = len(m)
    for row in range(1):
        for column in range(row, LEN - row - 1):
            """ First element """
            tmp = m[row][column]
            """ Left Bottom -> Clockwise """
            m[row][column] = m[LEN - 1 - column][row]
            m[LEN - 1 - column][row] = m[LEN - 1 - row][LEN - 1 - column]
            m[LEN - 1 - row][LEN - 1 - column] = m[column][LEN - 1 - row]
            m[column][LEN - 1 - row] = tmp
