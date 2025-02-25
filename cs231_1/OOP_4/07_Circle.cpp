#include<iostream>
using namespace std;

class circle{
    float radius;
public:
    circle(float r = 1.0);
    float area();
};

circle::circle(float r){
    radius = r;
}

float circle::area(){
    return 3.14159*radius*radius;
}

int main(){
    circle X = circle(1.5);
    cout<<"Area: "<<X.area()<<endl;
}