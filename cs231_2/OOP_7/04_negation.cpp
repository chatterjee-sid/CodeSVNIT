#include<iostream>
using namespace std;

class Numbers{
int x,y,z;
public:
    Numbers(int,int,int);
    friend Numbers operator -(Numbers);
    void display(); 
};

int main(){
    Numbers S(1,2,3);
    cout<<"S = ";
    S.display();
    Numbers T = -S;
    cout<<"S = ";
    S.display();
    cout<<"T = ";
    T.display();
    return 0;
}

Numbers::Numbers(int a, int b, int c){
    x = a;
    y = b;
    z = c;
}

Numbers operator -(Numbers T){
    return Numbers(-T.x,-T.y,-T.z);
}

void Numbers::display(){
    cout<<"x: "<<x<<", y: "<<y<<", z: "<<z<<endl;
}