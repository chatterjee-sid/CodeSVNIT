#include<iostream>
using namespace std;

int main(){
    int* normalptr = new int(256);
    int* arrayptr = new int[5]{342,435,635,23,439};
    cout<<"Pointer to integer: "<<normalptr<<endl;
    cout<<"Integer: "<<*normalptr<<endl;
    cout<<"Pointer to integer array: "<<arrayptr<<endl;
    cout<<"Pointer to integer array loop: "<<endl;
    for(int i=0; i<5; i++){
        cout<<(arrayptr+i)<<' ';
    }
    cout<<endl;
    cout<<"Integer array: "<<endl;
    for(int i=0; i<5; i++){
        cout<<*(arrayptr+i)<<' ';
    }
    cout<<endl;
    for(int i=0; i<5; i++)
    cout<<endl;
    delete normalptr;
    delete[] arrayptr;
    return 0;
}