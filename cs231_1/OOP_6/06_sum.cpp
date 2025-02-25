#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter length of array: ";
    cin>>n;
    int sum = 0;
    cout<<"Enter array: ";
    int *ptr = new int[n];
    for(int i=0;i<n;i++){
        cin>>*ptr++;
    }
    cout<<"Sum: ";
    for(int i=0;i<n;i++){
        sum += *--ptr;
    }
    cout<<sum;
    delete ptr;
    return 0;
}