#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int>& A){
    long long int n = A.size();
    for(int i=n-1; i>0; i--){
        bool swapped = false;
        for(int j=0;j<i;j++){
            if(A[j]>A[j+1]){
                swapped = true;
                A[j] = A[j+1] + A[j];
                A[j+1] = A[j] - A[j+1];
                A[j] = A[j] - A[j+1];
            }
        }
        if(!swapped) return;
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
        bubblesort(numbers);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double,milli> time = end-start;
        cout<<"Best case time: "<<time.count()<<"ms"<<endl;
    }
}