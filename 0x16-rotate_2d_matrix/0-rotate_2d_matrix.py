""" Rotates en 2D matrix in place """
def rotate_2d_matrix(matrix):

    for row in range(len(matrix)):
        for column in range(row):
            tmp = matrix[row][column]
            matrix[row][column] = matrix[column][row]
            matrix[column][row] = tmp
   
    for row in range(len(matrix)):
        i = len(matrix[row]) - 1
        tmp = matrix[row][i]
        matrix[row][i] = matrix[row][0]
        matrix[row][0] = tmp

