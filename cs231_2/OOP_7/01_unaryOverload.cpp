#include<iostream>
using namespace std;

class test{
public:
    int x;
    test(){
        x = 0;
    }
    test(int y){
        x = y;
    }
    inline void operator ++(){
        x = x+5;
    } //preincrement ++p
    inline void operator ++(int){
        x = x+5;
    } //postincrement p++
    inline void operator --(){
        x = x-5;
    } //predecrement --p
    inline void operator --(int){
        x = x-5;
    } //postdecrement p--
};

int main(){
    test t1;
    t1++;
    cout<<"PostIncrement: "<<t1.x<<endl;
    ++t1;
    cout<<"PreIncrement: "<<t1.x<<endl;
    t1--;
    cout<<"PostDecrement: "<<t1.x<<endl;
    --t1;
    cout<<"PreDecrement: "<<t1.x<<endl;
    return 0;
}