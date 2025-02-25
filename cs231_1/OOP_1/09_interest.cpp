#include<iostream>
using namespace std;

float pow(float r, int t){
    if(t==0) return r;
    return r*pow(r,t-1);
}

int main(){
    int p,t;
    float r;
    cout<<"Pricipal: ";
    cin>>p;
    cout<<"Rate (per annum): ";
    cin>>r;
    cout<<"Time (in years): ";
    cin>>t;
    //Simple interest
    float SI = p*r*t/100;
    //Compund interest
    float CI = p*pow((1+r/100),t) - p;
    cout<<"SI: "<<SI<<endl;
    cout<<"CI: "<<CI<<endl;
}