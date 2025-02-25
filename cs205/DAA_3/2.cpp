#include<iostream>
#include<vector>
using namespace std;

void insertionsort(vector<int>& S,int size){
    for(int i=1;i<size;i++){
        int key = S[i];
        int j = i;
        while(j>0 && S[j-1]<key){
            S[j] = S[j-1];
            j--;
        }
        S[j] = key;
    }
}

int main(){
    int n,k;
    cout<<"Enter no. of elements: ";
    cin>>n;
    vector<int> A(n);
    cout<<"Enter array: ";
    for(int i=0;i<n;i++) cin>>A[i];
    insertionsort(A,n);
    cout<<"Enter k: ";
    cin>>k;
    if(k>n) k = n;
    cout<<"kth largest: "<<A[k-1]<<endl;
    return 0;
}