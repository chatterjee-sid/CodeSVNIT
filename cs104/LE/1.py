def isphonenumber(num):
    if len(num)==13 and num[:4]=='0261' and num[4]=='-' and num[5:8].isdigit() and num[8]=='-' and num[9:].isdigit():
        return True
    else:
        return False
#__main__
num = input("Enter your number: ")
if isphonenumber(num):
    print("Yes")
else:
    print("No")