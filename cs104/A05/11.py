# 11. Write a Python script to concatenate the following dictionaries to create a new one.
# dic1={1:10, 2:20}, dic2={3:30, 4:40}, dic3={5:50,6:60}
dic1={1:10,2:20}
dic2={3:30,4:40}
dic3={5:50,6:60}
resdic={}
resdic.update(dic1)
resdic.update(dic2)
resdic.update(dic3)
print(resdic)