#include<iostream>
using namespace std;

float power(float);
float power(float,int);

int main(){
    float a,b;
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

float power(float base){
    return base*base;
}

float power(float base, int exp){
    float i = 1;
    for(int j=0;j<exp;j++){
        i*=base;
    }
    cout<<"result calculated for "<<base<<" raised to "<<exp<<endl;
    return i;
}