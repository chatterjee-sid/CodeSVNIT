#include<iostream>
#include<vector>
using namespace std;

void freqsort(vector<vector<int>>& S,int size){
    for(int i=1;i<size;i++){
        vector<int> key = S[i];
        int j = i;
        while(j>0 && S[j-1][0]<key[0]){
            S[j] = S[j-1];
            j--;
        }
        while(j>0 && S[j-1][0]==key[0] && S[j-1][1]>key[1]){
            S[j] = S[j-1];
            j--;
        }
        S[j] = key;
    }
}

int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    vector<int> A(n);
    cout<<"Enter array: ";
    int maxnum = 0;
    for(int i=0;i<n;i++){
        cin>>A[i];
        if(A[i]>maxnum) maxnum=A[i];
    }
    vector<vector<int>> S(maxnum, vector<int>(2));
    for(int i=0;i<maxnum;i++){
        S[i][1] = i+1;
        S[i][0] = 0;
    }
    for(int i=0;i<n;i++){
        S[A[i]-1][0]++;
    }
    freqsort(S,maxnum);
    int i=0,j=0;
    while(i<n){
        for(int k=0;k<S[j][0];k++){
            A[i] = S[j][1];
            i++;
        }
        j++;
    }
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<A[i]<<' ';
    }
    return 0;
}