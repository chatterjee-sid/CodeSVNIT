#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter length of array: ";
    cin>>n;
    cout<<"Enter array: ";
    int *ptr = new int[n];
    for(int i=0;i<n;i++){
        cin>>*ptr++;
    }
    cout<<"Reversed array: ";
    for(int i=0;i<n;i++){
        cout<<*--ptr<<' ';
    }
    delete ptr;
    return 0;
}