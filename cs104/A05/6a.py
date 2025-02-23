# 06. Write a Python program to remove an empty tuple(s) from a list of tuples.
# Method 1
def remove_empty_tuple(List):
    while True:
        try:
            List.remove(())
        except:
            break
        return List
L=[(),(),('',),('a','b'),('a','b','c'),('d')]
print(remove_empty_tuple(L))