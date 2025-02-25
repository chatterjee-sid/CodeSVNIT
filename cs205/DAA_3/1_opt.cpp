#include<bits/stdc++.h>
using namespace std;

void freqsort(vector<int>& A){
    unordered_map<int,int> frequency;
    for(int i=0;i<A.size();i++){
        frequency[A[i]]++;
    }
    vector<pair<int,int>> index;
    for(auto it: frequency){
        pair<int,int> temp;
        temp.first = it.second;
        temp.second = it.first;
        index.push_back(temp);
    }
    sort(index.begin(),index.end(), [](const pair<int,int>& p1, const pair<int,int>& p2){
        if(p1.first != p2.first) return p1.first > p2.first;
        else return p1.second < p2.second;
    });
    int i=0;
    for(int j=0;j<index.size();j++){
        for(int k=0;k<index[j].first;k++){
            A[i] = index[j].second;
            i++;
        }
    }
}

int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    vector<int> A(n);
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    freqsort(A);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<A[i]<<' ';
    }
    return 0;
}