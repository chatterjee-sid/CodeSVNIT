#include<iostream>
using namespace std;

int main(){
    string num;
    cout<<"Enter digits: ";
    cin>>num;
    for(int i=0;i<num.size();i++){
        for(int j=0;j<i;j++){
            cout<<"  ";
        }
        for(int j=i;j<num.size();j++){
            cout<<num[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}