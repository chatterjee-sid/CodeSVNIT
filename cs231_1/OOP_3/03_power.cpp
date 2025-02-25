#include<iostream>
using namespace std;

float power(float,int exp = 2);

int main(){
    int a,b;
    cout<<"2 Argument case"<<endl;
    cout<<"Enter base: ";
    cin>>a;
    cout<<"Enter exponent: ";
    cin>>b;
    cout<<"Result: "<<power(a,b)<<endl;
    cout<<"1 Argument case"<<endl;
    cout<<"Enter base: ";
    cin>>a;
    cout<<"Result: "<<power(a)<<endl;
}

float power(float base, int exp){
    float i = base;
    for(int j=0;j<exp;j++){
        i*=base;
    }
    cout<<"result calculated for "<<base<<" raised to "<<exp<<endl;
    return i;
}