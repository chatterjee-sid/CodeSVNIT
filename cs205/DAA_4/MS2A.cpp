#include<bits/stdc++.h>
using  namespace std;

void merge2(vector<int>& arr, int low, int mid, int high){
    vector<int> B1(mid-low), B2(high-mid);
    for(int i=low;i<mid;i++){
        B1[i-low] = arr[i];
    }
    for(int i=mid;i<high;i++){
        B2[i-mid] = arr[i];
    }
    int b1s = mid-low, b2s = high-mid;
    int i=0,j=0,k=low;
    while(i<b1s && j<b2s){
        if(B1[i]<=B2[j]){
            arr[k++] = B1[i++];
        } else{
            arr[k++] = B2[j++];
        }
    }
    while(i<b1s){
        arr[k++] = B1[i++];
    }
    while(j<b2s){
        arr[k++] = B2[j++];
    }
}
void mergesort2(vector<int>& arr,int low,int high){
    if(high-low<=1) return;
    int mid = low + (high-low)/2;
    mergesort2(arr,low,mid);
    mergesort2(arr,mid,high);
    merge2(arr,low,mid,high);
}

int main(){
    for(int i=0; i<10; i++){
        ifstream file("..\\Files\\File "+to_string(i+1)+".txt");
        vector<int> numbers;
        int num;
        while(file>>num){
            numbers.push_back(num);
        }
        sort(numbers.begin(),numbers.end());
        cout<<"File "<<i+1<<endl;
        auto start = chrono::high_resolution_clock::now();
        mergesort2(numbers,0,numbers.size());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double,milli> time = end-start;
        cout<<"Average case time: "<<time.count()<<"ms"<<endl;
    }
    return 0;
}