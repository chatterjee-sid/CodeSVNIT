#include<iostream>
using namespace std;

int main(){
    char *a = new char;
    string *b = new string;
    cout<<"Enter char and string: ";
    cin>>*a>>*b;
    cout<<"Char: "<<*a<<endl;
    cout<<"String: "<<*b<<endl;
    delete a;
    delete b;
    return 0;
}