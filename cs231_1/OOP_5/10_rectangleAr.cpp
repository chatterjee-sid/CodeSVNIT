#include<iostream>
using namespace std;

class Rectangle{
    float length;
    float width;
public:
    Rectangle(float,float);
    float area();
};

Rectangle::Rectangle(float a, float b){
    length = a;
    width = b;
}

inline float Rectangle::area(){
    return length*width;
}

int main(){
    float a,b;
    cout<<"Enter values a b: ";
    cin>>a>>b;
    Rectangle X(a,b);
    cout<<"Area of constructed rectangle: "<<X.area()<<endl;
}
