#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> A(n);
    int z0=0,z1=0,z2=0;
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>A[i];
        if(A[i]==0) z0++;
        else if(A[i]==1) z1++;
        else z2++;
    }
    for(int i=0;i<z0;i++) A[i] = 0;
    for(int i=z0;i<z0+z1;i++) A[i] = 1;
    for(int i=z0+z1;i<n;i++) A[i] = 2;
    cout<<"Final array: ";
    for(int i=0;i<n;i++) cout<<A[i]<<' ';
    return 0;
}