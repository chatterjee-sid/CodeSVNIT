#include<iostream>
#include<cmath>
using namespace std;

class Shape{
public:
    float area(float);
    float area(float,float);
    float area(float,float,float);
};

int main(){
    int id;
    Shape X;
    cout<<"Shape id:"<<endl;
    cout<<'\t'<<"1. Rectangle"<<endl;
    cout<<'\t'<<"2. Circle"<<endl;
    cout<<'\t'<<"3. Triangle"<<endl;
    cout<<"Enter Shape Id: ";
    cin>>id;
    switch (id){
    case 1:
        float l,w;
        cout<<"Enter length: ";
        cin>>l;
        cout<<"Enter width: ";
        cin>>w;
        cout<<"Area of rectangle: "<<X.area(l,w)<<endl;
        break;
    case 2:
        float r;
        cout<<"Enter radius: ";
        cin>>r;
        cout<<"Area of circle: "<<X.area(r)<<endl;
        break;
    case 3:
        float s1,s2,s3;
        cout<<"Enter side length1: ";
        cin>>s1;
        cout<<"Enter side length2: ";
        cin>>s2;
        cout<<"Enter side length3: ";
        cin>>s3;
        cout<<"Area of triangle: "<<X.area(s1,s2,s3)<<endl;
        break;
    default:
        cout<<"Error"<<endl;
        break;
    }
}

float Shape::area(float r){
    return 3.14*r*r;
}
float Shape::area(float l, float w){
    return l*w;
}
float Shape::area(float a, float b, float c){
    float s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}