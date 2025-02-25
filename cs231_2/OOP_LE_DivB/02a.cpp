#include<iostream>
using namespace std;

class Shape{
protected:
    double p1, p2, area;
public:
    void get_data(double a1, double a2 = 1){
        p1 = a1;
        p2 = a2;
    }
    virtual void display_area() = 0;
};
class Triangle : public Shape{
public:
    void display_area() override{
        cout<<"Triangle area: "<<p1*p2/2<<endl;
    }
};
class Rectangle : public Shape{
public:
    void display_area() override{
        cout<<"Rectangle area: "<<p1*p2<<endl;
    }
};
class Circle : public Shape{
public:
    void display_area() override{
        cout<<"Circle area: "<<3.141593*p1*p1<<endl;
    }
};
int main(){
    Triangle T;
    T.get_data(2.5,3.5);
    T.display_area();
    Rectangle R;
    R.get_data(2.5,3.5);
    R.display_area();
    Circle C;
    C.get_data(2.5);
    C.display_area();
    return 0;
}