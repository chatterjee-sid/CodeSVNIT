#include<iostream>
using namespace std;

class Land{
protected:
    string name;
public:
    Land(string x){
        name = x;
    }
    void walk(){
        cout<<name<<" walks on land."<<endl;
    }
};

class Water{
protected:
    string name;
public:
    Water(string x){
        name = x;
    }
    void swim(){
        cout<<name<<" swims in water"<<endl;
    }
};

class Frog: public Land, public Water{
public:
    Frog(string x) : Land(x), Water(x){}
    void speak(){
        cout<<"Ribit ribit!"<<endl;
        cout<<"("<<Land::name<<" is happy)"<<endl;
    }
};

int main(){
    Frog F("Kero");
    F.swim();
    F.walk();
    F.speak();
    return 0;
}