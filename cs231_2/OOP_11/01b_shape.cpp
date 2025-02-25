#include<iostream>
using namespace std;

class shape{
protected:
    double height;
    double base;
public:
    void getdata(double a, double b){
        height = a;
        base = b;
    }
    virtual void displayarea() = 0;
};

class triangle : public shape{
public:
    void displayarea() override{
        cout<<"Triangle Area: "<<height*base*0.5<<endl;
    }
};

class rectangle : public shape{
public:
    void displayarea() override{
        cout<<"Rectangle Area: "<<height*base<<endl;
    }
};

int main(){
    int ch;
    double p,q;
    while(1){
        cout<<"1. Triangle"<<endl;
        cout<<"2. Rectangle"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter option: ";
        cin>>ch;
        if(ch==0){
            cout<<"Thank you"<<endl;
            break;
        }
        if(ch!=1 && ch!=2){
            cout<<"INVALID INPUT"<<endl;
            continue;
        }
        cout<<"Enter height: ";
        cin>>p;
        cout<<"Enter base: ";
        cin>>q;
        shape* S;
        if(ch==1){
            S = new triangle;
        } else{
            S = new rectangle;
        }
        S->getdata(p,q);
        S->displayarea();
        delete S;
    }
    return 0;
}