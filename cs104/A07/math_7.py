def round(num):
    num*=1000
    if num%1>0.5:
        num=int(num)+1
    else:
        num=int(num)
    return num/1000
def floor(num):
    if num>0:
        return int(num)
    else:
        return int(num)-1
def ceil(num):
    if num%1==0 or num<0:
        return int(num)
    else:
        return int(num)+1
def hello(user):
    print("Hello",user,"!")