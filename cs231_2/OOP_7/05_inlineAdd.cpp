#include<iostream>
using namespace std;

inline int sum(int, int);

int main(){
    int a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    cout<<"Sum: "<<sum(a,b)<<endl;
    return 0;
}

int sum(int a, int b){
    return a+b;
}