#include<iostream>
using namespace std;

void pointer_swap(int*,int*);
void reference_swap(int&,int&);
void value_swap(int,int);

int main(){
    int a,b;
    cout<<"Call by value"<<endl;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    value_swap(a,b);
    cout<<"New a (outside func): "<<a<<endl;
    cout<<"New b (outside func): "<<b<<endl;
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

void value_swap(int x, int y){
    x = x + y;
    y = x - y;
    x = x - y;
    cout<<"New a (inside func): "<<x<<endl;
    cout<<"New b (inside func): "<<y<<endl;
    cout<<"No change to original in value_swap"<<endl;
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