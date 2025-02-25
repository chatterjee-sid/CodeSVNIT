#include<iostream>
using namespace std;

string func();
string func(int);
string func(int,int);

int main(){
    cout<<"0 Args: "<<func()<<endl;
    cout<<"1 Arg: "<<func(1)<<endl;
    cout<<"2 Arg: "<<func(1,2)<<endl;
}

string func(){
    return "aaa";
}

string func(int a){
    return "bbb";
}

string func(int a, int b){
    return "ccc";
}