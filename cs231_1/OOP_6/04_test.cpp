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
    Test t1, t2, t3, t4, t5;
    return 0;
}

Test::Test(){
    count++;
    cout<<"Object No. "<<count<<" created."<<endl;
}

Test::~Test(){
    cout<<"Object No. "<<count<<" destroyed."<<endl;
    count--;
}