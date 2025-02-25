#include<iostream>
using namespace std;

inline int max(int,int);
inline int min(int,int);

int main(){
    int a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    cout<<"Maximum: "<<max(a,b)<<endl;
    cout<<"Minimum: "<<min(a,b)<<endl;
    return 0;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int min(int a, int b){
    return (a>b)?b:a;
}