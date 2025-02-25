#include<iostream>
using namespace std;

int factorial(int num){
    int value = 1;
    for(int i=2; i<=num; i++){
        value *= i;
    }
    return value;
}

int main(){
    int (*ptrfact) (int);
    ptrfact = &factorial;
    cout<<ptrfact(7)<<endl;
    return 0;
}