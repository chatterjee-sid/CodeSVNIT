#include<bits/stdc++.h>
using namespace std;

void insertionsort(vector<int>& A){
    long long int n = A.size();
    for(int i=1;i<n;i++){
        int key = A[i];
        int j = i;
        while(j>0 && A[j-1]>key){
            A[j] = A[j-1];
            j--;
        }
        A[j] = key;
    }
}

int main(){
    cout<<"Average case"<<endl;
    for(int i=0; i<10; i++){
        ifstream file("..\\..\\Files\\File "+to_string(i+1)+".txt");
        vector<int> numbers;
        int num;
        while(file>>num){
            numbers.push_back(num);
        }
        cout<<"File "<<i+1<<endl;
        auto start = chrono::high_resolution_clock::now();
        insertionsort(numbers);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double,milli> time = end-start;
        cout<<"Average time: "<<time.count()<<"ms"<<endl;
    }
}