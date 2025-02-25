#include<iostream>
using namespace std;

class X{
    int value;
public:
    X(int val=0){
        value = val;
    }
    friend void swap(X*, X*);
    void showVal(){
        cout<<"Current value is "<<value;
    }
};

void swap(X* x1, X* x2){
    int temp = x1->value;
    x1->value = x2->value;
    x2->value = temp;
}

int main(){
    X a(2),b(3);
    cout<<"Object a: ";
    a.showVal();
    cout<<endl;
    cout<<"Object b: ";
    b.showVal();
    cout<<endl;
    swap(&a,&b);
    cout<<"Object a: ";
    a.showVal();
    cout<<endl;
    cout<<"Object b: ";
    b.showVal();
    cout<<endl;
    return 0;
}