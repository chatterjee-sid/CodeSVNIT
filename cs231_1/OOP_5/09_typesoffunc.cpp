#include<iostream>
using namespace std;

void avg1();
float avg2();
void avg3(float,float);
float avg4(float,float);

int main(){
    //Case 1
    avg1();
    cout<<endl;
    //Case 2
    cout<<"Avg: "<<avg2();
    cout<<endl;
    //Case 3
    float a,b;
    cout<<"Enter values a b: ";
    cin>>a>>b;
    avg3(a,b);
    cout<<endl;
    //Case 4
    cout<<"Enter values a b: ";
    cin>>a>>b;
    cout<<"Avg: "<<avg4(a,b);
    cout<<endl;
}

void avg1(){
    float a,b;
    cout<<"Enter values a b: ";
    cin>>a>>b;
    cout<<"Avg: "<<(a+b)/2;
}

float avg2(){
    float a,b;
    cout<<"Enter values a b: ";
    cin>>a>>b;
    return (a+b)/2;
}

void avg3(float a, float b){
    cout<<"Avg: "<<(a+b)/2;
}

float avg4(float a, float b){
    return (a+b)/2;
}