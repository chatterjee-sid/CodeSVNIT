#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
    int a,e;
    float b,c,d;
    string f,g;
    cout<<"Input: ";
    cin>>a;
    cout<<"Output: "<<a<<endl<<"Input: ";
    cin>>b;
    cout<<"Output: "<<fixed<<setprecision(4)<<b<<endl<<"Input: ";
    cin>>c;
    cout<<"Output: "<<fixed<<setprecision(4)<<c<<endl<<"Input: ";
    cin>>d;
    cout<<"Output: "<<fixed<<setprecision(2)<<d<<endl<<"Input: ";
    cin>>e;
    cout<<"Output: "<<e<<'*'<<e<<endl;
    string temp;
    getline(cin,temp);
    cout<<"Input: ";
    getline(cin,f);
    cout<<"Output: "<<f<<endl;
    cout<<"Input: ";
    getline(cin,g);
    cout<<"Output: "<<g<<endl;
    return 0;
}