#include<bits/stdc++.h>
using namespace std;

long long int findval(vector<int>& A, int val){
    long long int n = A.size();
    for(int i=0;i<n;i++){
        if(A[i]==val) return i;
    }
    return -1;
}

int main(){
    cout<<"Worst Case: element does not exist in array"<<endl;
    for(int i=0; i<10; i++){
        ifstream file("..\\..\\Files\\File "+to_string(i+1)+".txt");
        vector<int> numbers;
        int num;
        while(file>>num){
            numbers.push_back(num);
        }
        cout<<"File "<<i+1<<endl;
        long long int time = 0;
        for(int i=0;i<100;i++)
        {
            auto start = chrono::high_resolution_clock::now();
            findval(numbers,-1);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double,milli>ctime = end-start;
            time += ctime.count();
        }
        cout<<"Average time: "<<time/100.0<<"ms"<<endl;
    }
}