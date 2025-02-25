#include<iostream>
using namespace std;

class PLUSData{
protected:
    int n1, n2;
public:
    PLUSData(int a, int b){
        n1 = a;
        n2 = b;
    }
};

class Addition: protected PLUSData{
public:
    Addition(int a, int b) : PLUSData(a,b){}
    int add(){
        return n1+n2;
    }
};

int main(){
    int p,q;
    cin>>p>>q;
    Addition X(p,q);
    cout<<X.add()<<endl;   
    return 0;
}