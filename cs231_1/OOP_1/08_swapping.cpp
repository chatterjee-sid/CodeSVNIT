#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Swapping with 3rd variable"<<endl;
    cout<<"A: ";
    cin>>a;
    cout<<"B: ";
    cin>>b;
    int c = a;
    a = b;
    b = c;
    cout<<"After swap:"<<endl;
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;
    cout<<endl;
    cout<<"Swapping without 3rd variable"<<endl;
    cout<<"A: ";
    cin>>a;
    cout<<"B: ";
    cin>>b;
    a = a+b;
    b = a-b;
    a = a-b;
    cout<<"After swap:"<<endl;
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;
}