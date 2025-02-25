#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of terms: ";
    cin>>n;
    int s = 0;
    for(int i=1;i<=n;i++){
        s+=i;
        cout<<i<<' ';
    }
    cout<<endl<<"Sum: "<<s<<endl;
    return 0;
}