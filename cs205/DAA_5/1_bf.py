def Skyline(A):
    min,max = float('inf'),0
    for i in range(len(A)):
        if A[i][0]<min:
            min = A[i][0]
        if A[i][1]>max:
            max = A[i][1]
    B = [0 for i in range(max-min)]
    for i in range(len(A)):
        for j in range(A[i][0]-min,A[i][1]-min):
            if B[j]<A[i][2]:
                B[j] = A[i][2]
    res = []
    res.append([min,B[0]])
    for i in range(1,len(B)):
        if B[i] !=  B[i-1]:
            res.append([min+i,B[i]])
    return res

L = [[33,41,5],[4,9,21],[30,36,9],[14,18,11],[2,12,14],[34,43,19],[23,25,8],[14,21,16],[32,37,12],[7,16,7],[24,27,10]]

print(Skyline(L))