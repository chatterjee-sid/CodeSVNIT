#include<iostream>
using namespace std;

class Test{
public:
    static int count;
    Test();
    ~Test();
};

int Test::count = 0;

int main(){
    Test* ptr = new Test[5];
    delete[] ptr;
    return 0;
}

Test::Test(){
    cout<<"Object no. "<<++count<<" created"<<endl;
}

Test::~Test(){
    cout<<"Object no. "<<count--<<" destroyed"<<endl;
}