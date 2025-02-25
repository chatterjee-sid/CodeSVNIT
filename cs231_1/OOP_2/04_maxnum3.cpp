#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cout<<"Enter 3 numbers: ";
    cin>>a>>b>>c;
    int max = a;
    if(b>max) max = b;
    if(c>max) max = c;
    cout<<"Max number: "<<max<<endl;
    return 0;
}