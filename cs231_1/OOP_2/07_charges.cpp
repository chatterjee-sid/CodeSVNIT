#include<iostream>
using namespace std;

int main(){
    string user;
    cout<<"Subscriber name: ";
    cin>>user;
    int n;
    cout<<"Units consumed: ";
    cin>>n;
    float charge = 0.0;
    if(n<=100){
        charge = n*0.6;
    } else if(n<=300){
        charge = n*0.8 - 20; // 60 + (n-100)*0.8
    } else{
        charge = n*0.9 - 50; // 60 + 160 + (n-300)*0.9
    }
    charge = charge<50?50:charge;
    charge = charge>300?charge*1.15:charge;
    cout<<"Electricity bill for "<<user<<" amounts to Rs."<<charge<<endl;
}