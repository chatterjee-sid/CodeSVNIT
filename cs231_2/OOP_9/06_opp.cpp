#include<iostream>
using namespace std;

class X{
public:
    int count;
    X(int count = 0){
        this->count = count;
    }
    X operator++(){
        count = count + 1;
        return *this;
    }
    X operator++(int){
        count = count + 1;
        return X(count-1);
    }
};

int main(){
    X x;
    cout<<"Postfix: "<<(x++).count<<endl;
    cout<<"Prefix: "<<(++x).count<<endl;
    cout<<"Finally: "<<x.count<<endl;
    return 0;
}