#include<iostream>
using namespace std;

int add();
int add(int,int);
int add(int,int,int);
int add(int,int,int,int);

int prod();
int prod(int,int);
int prod(int,int,int);
int prod(int,int,int,int);

int main(){
    cout<<"Zero Arg Add: "<<add()<<endl;
    cout<<"Two Arg Add: "<<add(2,3)<<endl;
    cout<<"Three Arg Add: "<<add(2,3,4)<<endl;
    cout<<"Four Arg Add: "<<add(2,3,4,5)<<endl;
    cout<<"Zero Arg Prod: "<<prod()<<endl;
    cout<<"Two Arg Prod: "<<prod(2,3)<<endl;
    cout<<"Three Arg Prod: "<<prod(2,3,4)<<endl;
    cout<<"Four Arg Prod: "<<prod(2,3,4,5)<<endl;
}

int add(){
    int a,b;
    cout<<"Enter numbers: ";
    cin>>a>>b;
    return a+b;
}

int add(int a, int b){
    return a+b;
}

int add(int a, int b, int c){
    return a+b+c;
}

int add(int a, int b, int c, int d){
    return a+b+c+d;
}

int prod(){
    int a,b;
    cout<<"Enter numbers: ";
    cin>>a>>b;
    return a*b;
}

int prod(int a, int b){
    return a*b;
}

int prod(int a, int b, int c){
    return a*b*c;
}

int prod(int a, int b, int c, int d){
    return a*b*c*d;
}