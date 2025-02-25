#include<iostream>
using namespace std;

class Animal{
protected:
    string name;
public:
    Animal(string x){
        name = x;
    }
    void eat(){
        cout<<name<<" is eating."<<endl;
    }
};

class Dog: public Animal{
public:
    Dog(string x) : Animal(x){}
    void speak(){
        cout<<"Bhow wow!"<<endl;
        cout<<"("<<name<<" is happy)"<<endl;
    }
};

int main(){
    Dog D("Inu");
    D.eat();
    D.speak();
    return 0;
}