#include<iostream>
using namespace std;

class complex{
    int x = 0;
    int y = 0;
public:
    complex(int,int);
    inline complex operator + (complex&);
    void form();
};

int main(){
    complex A(3,4);
    complex B(5,8);
    complex C = A+B;
    cout<<"Complex A: ";
    A.form();
    cout<<"Complex B: ";
    B.form();
    cout<<"Complex C: ";
    C.form();
    return 0;
}

complex::complex(int p, int q){
    x = p;
    y = q;
}

complex complex::operator+ (complex& T){
    int p = x + T.x;
    int q = y + T.y;
    complex S(p,q);
    return S;
}

void complex::form(){
    cout<<x<<" + "<<y<<"j"<<endl;
}