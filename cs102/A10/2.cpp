// 2. Write a program to implement linear search using array.
#include<iostream>
using namespace std;
int main(){
    int array[] = {3,8,7,1,12,6,4,2,11,13,10,9,5};
    int len = sizeof(array)/sizeof(int);
    int data;
    cin>>data;
    int flag=1;
    for(int i=0;i<len;i++){
        if(array[i]==data){
            cout<<"Index: "<<i;
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<"Element not found.";
    }
}