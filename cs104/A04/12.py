#12. WAP to calculate grade of a student on basis of marks of 5 subjects
L=[]
i=0
while i<5:
    A=int(input("Enter marks of subject "+str(i+1)+": "))
    if A>=0 and A<=100:
        L.append(A)
        i+=1
    else:
        print("Marks must be between 0 and 100")
sum=0
for i in L:
    sum+=i
avg=sum/5
if avg>85:
    grade="A"
elif avg>70:
    grade="B"
elif avg>55:
    grade="C"
elif avg>40:
    grade="D"
else:
    grade="E"
print("Score:",avg)
print("Grade:",grade)