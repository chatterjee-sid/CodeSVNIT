def splitMatrix(matrix):
    row = len(matrix)
    col = len(matrix[0])
    row2 = row // 2
    col2 = col // 2
    top_left = [row[:col2] for row in matrix[:row2]]
    top_right = [row[col2:] for row in matrix[:row2]]
    bottom_left = [row[:col2] for row in matrix[row2:]]
    bottom_right = [row[col2:] for row in matrix[row2:]]
    return top_left, top_right, bottom_left, bottom_right

def addMatrices(A, B):
    result = [[A[i][j] + B[i][j]  for j in range(len(A[0]))] for i in range(len(A))]
    return result

def MatrixMultiply(A,B):
    n = len(A)
    if n==1:
        return [[A[0][0]*B[0][0]]]
    A11, A12, A21, A22 = splitMatrix(A)
    B11, B12, B21, B22 = splitMatrix(B)
    C11 = addMatrices(MatrixMultiply(A11, B11), MatrixMultiply(A12, B21))
    C12 = addMatrices(MatrixMultiply(A11, B12), MatrixMultiply(A12, B22))
    C21 = addMatrices(MatrixMultiply(A21, B11), MatrixMultiply(A22, B21))
    C22 = addMatrices(MatrixMultiply(A21, B12), MatrixMultiply(A22, B22))
    C = []
    for i in range(n//2):
        C.append(C11[i] + C12[i])
    for i in range(n-n//2):
        C.append(C21[i] + C22[i])
    return C

L1 = [[3,9,1,7],[2,5,8,4],[6,1,3,9],[8,7,2,6]]
L2 = [[5,2,9,1],[7,3,6,8],[4,1,5,2],[9,6,7,3]]
for row in MatrixMultiply(L1,L2):
    print(row)