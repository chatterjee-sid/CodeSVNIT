#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    int n1 = n;
    int digitcnt = 0;
    while(n1){
        digitcnt++;
        n1/=10;
    }
    int armcheck = 0;
    n1 = n;
    while(n1){
        int d = 1;
        for(int i=0;i<digitcnt;i++){
            d *= (n1%10);
        }
        armcheck += d;
        n1/=10;
    }
    if(n==armcheck) cout<<"Armstrong"<<endl;
    else cout<<"Not armstrong"<<endl;
    return 0;
}