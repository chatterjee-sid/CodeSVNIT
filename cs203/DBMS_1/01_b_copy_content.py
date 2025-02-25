old = open("DBMS\\DBMS_1\\01_myfile.txt","r")
new = open("DBMS\\DBMS_1\\01_mynewfile.txt","w")
a = old.read()
new.write(a)
old.close()
new.close()

'''
new.writelines(old.readlines())
'''