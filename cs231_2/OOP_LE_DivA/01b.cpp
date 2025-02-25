#include<iostream>
#include<vector>
using namespace std;

class Shape{
public:
    virtual void area() = 0;
};

class Rectangle : public Shape{
    float l,b;
public:
    Rectangle(float l, float b){
        this->l = l;
        this->b = b;
    }
    void area() override{
        cout<<"Rectangle area: "<<l*b<<endl;
    }
};

class Circle : public Shape{
    float r;
public:
    Circle(float r){
        this->r = r;
    }
    void area() override{
        cout<<"Circle area: "<<3.14159*r*r<<endl;
    }
};

int main(){
    vector<Shape*> ShapeList;
    while(1){
        int ch;
        cout<<"Menu: "<<endl;
        cout<<"1. Rectangle"<<endl;
        cout<<"2. Circle"<<endl;
        cout<<"0. Exit"<<endl;
        cin>>ch;
        if(ch==1){
            float l,b;
            cout<<"Enter length: ";
            cin>>l;
            cout<<"Enter breadth: ";
            cin>>b;
            ShapeList.push_back(new Rectangle(l,b));
            ShapeList[ShapeList.size()-1]->area();
        } else if(ch==2){
            float r;
            cout<<"Enter radius: ";
            cin>>r;
            ShapeList.push_back(new Circle(r));
            ShapeList[ShapeList.size()-1]->area();
        } else if(ch==0){
            cout<<"Thank you"<<endl;
            for(auto shape: ShapeList){
                delete shape;
            }
            break;
        } else{
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}