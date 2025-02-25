#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter no. of elements: ";
    cin>>n;
    vector<int> A(n);
    cout<<"Enter array: ";
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<"Enter k: ";
    cin>>k;
    if(k>n) k = n;
    sort(A.begin(),A.end(),greater<int>());
    cout<<"kth largest: "<<A[k-1]<<endl;
    return 0;
}