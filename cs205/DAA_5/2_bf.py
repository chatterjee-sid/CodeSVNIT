def MatrixMultiply(A,B):
    C = [[0 for i in range(len(A))] for j in range(len(B[0]))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                C[i][j] += A[i][k]*B[k][j]
    return C

L1 = [[3,9,1,7],[2,5,8,4],[6,1,3,9],[8,7,2,6]]
L2 = [[5,2,9,1],[7,3,6,8],[4,1,5,2],[9,6,7,3]]
for i in MatrixMultiply(L1,L2):
    print(i)