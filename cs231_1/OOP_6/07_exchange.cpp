#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter value of a: ";
    cin>>a;
    cout<<"Enter value of b: ";
    cin>>b;
    int *pa = &a, *pb = &b;
    *pa = *pa + *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb;
    cout<<"Value of a: "<<a<<endl;
    cout<<"Value of b: "<<b<<endl;
    return 0;
}