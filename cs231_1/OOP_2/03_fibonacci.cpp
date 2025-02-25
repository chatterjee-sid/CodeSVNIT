#include<iostream>
using namespace std;

int main(){
    int a=0, b=1;
    int n;
    cout<<"Enter no. of terms: ";
    cin>>n;
    if(n>=1) cout<<0;
    if(n>=2) cout<<' '<<1;
    if(n>=3){
        for(int i=3;i<=n;i++){
            int c = a+b;
            a = b;
            b = c;
            cout<<' '<<c;
        }
    }
    cout<<endl;
    return 0;
}