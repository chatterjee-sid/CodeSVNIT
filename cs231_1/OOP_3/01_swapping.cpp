#include<iostream>
using namespace std;

void pointer_swap(int*,int*);
void reference_swap(int&,int&);

int main(){
    int a,b;
    cout<<"Call by value"<<endl;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout<<"New a: "<<a<<endl;
    cout<<"New b: "<<b<<endl;
    cout<<"Call by address"<<endl;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    pointer_swap(&a,&b);
    cout<<"New a: "<<a<<endl;
    cout<<"New b: "<<b<<endl;
    cout<<"Call by reference variable"<<endl;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    reference_swap(a,b);
    cout<<"New a: "<<a<<endl;
    cout<<"New b: "<<b<<endl;
}

void pointer_swap(int* x, int* y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void reference_swap(int& x, int& y){
    x = x + y;
    y = x - y;
    x = x - y;
}