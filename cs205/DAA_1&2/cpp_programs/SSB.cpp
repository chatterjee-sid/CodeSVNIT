#include<bits/stdc++.h>
using namespace std;

void selectionsort(vector<int>& A){
    long long int n = A.size();
    for(int i=0;i<n-1;i++){
        long long int k = i;
        for(int j=i+1;j<n;j++){
            if(A[k]>A[j]){
                k = j;
            }
        }
        A[i] = A[i] + A[k];
        A[k] = A[i] - A[k];
        A[i] = A[i] - A[k];
    }
}

int main(){
    cout<<"Best Case: sorted array"<<endl;
    for(int i=0; i<10; i++){
        ifstream file("..\\..\\Files\\File "+to_string(i+1)+".txt");
        vector<int> numbers;
        int num;
        while(file>>num){
            numbers.push_back(num);
        }
        sort(numbers.begin(),numbers.end());
        cout<<"File "<<i+1<<endl;
        auto start = chrono::high_resolution_clock::now();
        selectionsort(numbers);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double,milli> time = end-start;
        cout<<"Best Case time: "<<time.count()<<"ms"<<endl;
    }
}