#include<iostream>
using namespace std;

class clock{
public:
    int HH;
    int MM;
    int SS;
    clock(int);
    void display();
};

clock::clock(int sec){
    SS = sec%60;
    sec -= SS;
    sec /= 60;
    MM = sec%60;
    sec -= MM;
    sec /= 60;
    HH = sec;
}

void clock::display(){
    cout<<HH<<':'<<MM<<':'<<SS<<endl;
}

int main(){
    int sec;
    cout<<"Enter time in seconds: ";
    cin>>sec;
    clock myclock(sec);
    myclock.display();
}