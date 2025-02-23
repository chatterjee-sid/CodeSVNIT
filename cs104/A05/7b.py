#07. Write a Python program to sort a tuple by its float element.
def sort_by_float(List):
    L=[]
    for i in List:
        L.append((i[1],i[0]))
    L.sort(reverse=True)
    M=[]
    for i in L:
        M.append((i[1],i[0]))
    return M
Items = [('item1', '12.20'), ('item2', '15.10'), ('item3', '24.5')]
print(sort_by_float(Items))