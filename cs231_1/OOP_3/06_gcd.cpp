#include<iostream>
using namespace std;

int gcd(int,int);

int main(){
    int a,b;
    cout<<"Enter number a: ";
    cin>>a;
    cout<<"Enter number b: ";
    cin>>b;
    cout<<"GCD of a and b is "<<gcd(a,b);
}

int gcd(int a, int b){
    int r;
    if(a>b){
        r = a%b;
        if(r==0) return b;
        return gcd(b,r);
    } else{
        r = b%a;
        if(r==0) return a;
        return gcd(a,r);
    }
}