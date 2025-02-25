#include<iostream>
using namespace std;

int main(){
    int length, width;
    cout<<"Length: ";
    cin>>length;
    cout<<"Width: ";
    cin>>width;
    cout<<"Area: "<<length*width<<endl;
    cout<<"Perimeter: "<<2*(length+width)<<endl;
    return 0;
}