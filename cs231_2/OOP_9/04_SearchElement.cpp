#include<iostream>
using namespace std;

int main(){
    int array[] = {3,8,7,1,12,6,4,2,11,13,10,9,5};
    int* ptr = array;
    int n;
    cout<<"Enter element to find: ";
    cin>>n;
    for(int i=0; i<13; i++){
        if(ptr[i]==n){
            cout<<"Element found at index "<<i<<endl;
            ptr = array;
            break;
        }
        if(i==12){
            cout<<"Element not found"<<endl;
        }
    }
    return 0;
}