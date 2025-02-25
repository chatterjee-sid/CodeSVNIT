#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i=0; i<10; i++){
        ifstream file(".\\..\\Files\\File "+to_string(i+1)+".txt");
        vector<int> numbers;
        int num;
        while(file>>num){
            numbers.push_back(num);
        }
        cout<<"File "<<i+1<<endl;
        {
            auto start = chrono::high_resolution_clock::now();
            sort(numbers.begin(),numbers.end());
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double,milli> time = end-start;
            cout<<"Average case time: "<<time.count()<<"ms"<<endl;
        }
        {
            auto start = chrono::high_resolution_clock::now();
            sort(numbers.begin(),numbers.end());
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double,milli> time = end-start;
            cout<<"Best case time: "<<time.count()<<"ms"<<endl;
        }
        {
            reverse(numbers.begin(),numbers.end());
            auto start = chrono::high_resolution_clock::now();
            sort(numbers.begin(),numbers.end());
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double,milli> time = end-start;
            cout<<"Worst case time: "<<time.count()<<"ms"<<endl;
        }
    }
    return 0;
}