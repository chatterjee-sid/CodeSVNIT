#include<iostream>
using namespace std;

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

class Mammal: public Animal{
protected:
    int legs;
public:
    Mammal(string x, int l) : Animal(x){
        legs = l;
    }
    void walk(){
        cout<<name<<" walks on "<<legs<<" legs"<<endl;
    }
};

class Dog: public Mammal{
public:
    Dog(string x, int l) : Mammal(x,l){}
    void speak(){
        cout<<"Bhow wow!"<<endl;
        cout<<"("<<name<<" is happy)"<<endl;
    }
};

int main(){
    Dog D("Inu",4);
    D.eat();
    D.walk();
    D.speak();
    return 0;
}