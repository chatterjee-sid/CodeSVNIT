myfile = open("03_index.txt","r")
A = myfile.read().strip().split('\n')
N = input("Enter index: ")
high = len(A)-1
low = 0
idx = -1
while high>=low:
    mid = (high+low)//2
    S = A[mid][:8]
    if S>N:
        high = mid-1
    elif S<N:
        low = mid+1
    else:
        idx = int(A[mid][8:].strip())
        break
myfile.close()
if idx==-1:
    print("Record does not exit")
else:
    myfile = open("03_data.txt","r")
    print(myfile.read(45))
    myfile.seek(47*idx)
    print(myfile.read(45))
    myfile.close()