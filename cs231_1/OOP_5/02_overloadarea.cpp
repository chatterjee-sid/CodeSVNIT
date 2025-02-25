#include<iostream>
using namespace std;

float area(float);
float area(float,float);

int main(){
    int id;
    cout<<"Shape id:"<<endl;
    cout<<'\t'<<"1. Circle"<<endl;
    cout<<'\t'<<"2. Square"<<endl;
    cout<<'\t'<<"3. Rectangle"<<endl;
    cout<<"Enter Shape Id: ";
    cin>>id;
    switch (id)
    {
    case 1:
        float r;
        cout<<"Enter radius: ";
        cin>>r;
        cout<<"Area of circle: "<<area(r)<<endl;
        break;
    case 2:
        float s;
        cout<<"Enter side length: ";
        cin>>s;
        cout<<"Area of square: "<<area(s,s)<<endl;
        break;
    case 3:
        float l,w;
        cout<<"Enter lenght: ";
        cin>>l;
        cout<<"Enter width: ";
        cin>>w;
        cout<<"Area of rectangle: "<<area(l,w)<<endl;
        break;
    default:
        cout<<"Error"<<endl;
        break;
    }
}

float area(float r){
    return 3.14*r*r;
}
float area(float l, float w){
    return l*w;
}