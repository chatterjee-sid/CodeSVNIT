#06. Write a Python program to remove an empty tuple(s) from a list of tuples.
# Method 2
def remove_empty_tuple(List):
    for i in range(len(List)-1,-1,-1):
        if List[i]==():
            List.pop(i)
    return List
L=[(),(),('',),('a','b'),('a','b','c'),('d')]
print(remove_empty_tuple(L))