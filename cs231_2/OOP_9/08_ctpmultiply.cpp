#include<iostream>
using namespace std;

float multiplication(float a, float b) {return a*b;}
float multiplication(float a, float b, float c) {return a*b*c;}

int main(){
    cout<<"2-param: "<<multiplication(3,4)<<endl;
    cout<<"3-param: "<<multiplication(3,4,5)<<endl;
    return 0;
}