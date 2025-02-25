#include<iostream>
#include<cmath>
using namespace std;

int main(){
    float radius;
    cout<<"Radius: ";
    cin>>radius;
    cout<<"Area: "<<radius*radius*atan(1)*4;
    return 0;
}