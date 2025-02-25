#include<iostream>
using namespace std;

inline int sum(int, int);
inline int sum(int, int, int);

int main(){
    cout<<sum(33,28)<<endl;
    cout<<sum(31,24,56)<<endl;    
    return 0;
}

int sum(int a, int b){
    return a+b;
}

int sum(int a, int b, int c){
    return a+b+c;
}