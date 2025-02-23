# 02. Write a Python program to count the number of strings from a given list of strings. The string length is 2 or more and the first and last characters are the same.
L=['abbba','xybdmz','cvnhf','aba','1221']
cnt=0
for i in L:
    if len(i)>1 and i[0]==i[-1]:
        cnt+=1
print(cnt)