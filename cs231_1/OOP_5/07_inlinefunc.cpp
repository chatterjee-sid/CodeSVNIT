#include<iostream>
using namespace std;

inline float cube(float a){
    return a*a*a;
}

int main(){
    float a;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Cube of a: "<<cube(a)<<endl;
}