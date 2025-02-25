#include<iostream>
using namespace std;

class Complex{
    float x;
    float y;
public:
    Complex(float a, float b){
        x = a;
        y = b;
    }
    Complex operator+ (float S){
        return Complex(x+S,y);
    }
    Complex operator+ (Complex S){
        return Complex(x+S.x, y+S.y);
    }
    Complex operator- (float S){
        return Complex(x-S,y);
    }
    Complex operator- (Complex S){
        return Complex(x-S.x, y-S.y);
    }
    Complex operator* (float S){
        return Complex(x*S,y*S);
    }
    Complex operator* (Complex S){
        return Complex(x*S.x - y*S.y, x*S.y + y*S.x);
    }
    Complex operator/ (float S){
        if(S==0){
            cout<<"Divide by zero error: Value copied"<<endl;
            return *this;
        }
        return Complex(x/S,y/S);
    }
    Complex operator/ (Complex S){
        if (S.x==0 && S.y==0){
            cout<<"Divide by zero error: Value copied"<<endl;
            return *this;
        }
        return Complex(x,y)*Complex(S.x,-S.y)/(S.x*S.x  + S.y*S.y);
    }
    friend ostream& operator<< (ostream& output, Complex S){
        if (S.x==0){
            if (S.y!=0) output<<S.y<<"j";
            else output<<0;
        } else{
            if (S.y==0) output<<S.x;
            else if (S.y>0) output<<S.x<<"+"<<S.y<<"j";
            else output<<S.x<<S.y<<"j";
        }
        return output;
    }
};
int main(){
    Complex A(3,4);
    Complex B(5,-6);
    cout<<"A = "<<A<<endl;
    cout<<"B = "<<B<<endl;
    cout<<"A+B = "<<(A+B)<<endl;
    cout<<"A-B = "<<(A-B)<<endl;
    cout<<"A*B = "<<(A*B)<<endl;
    cout<<"A/B = "<<(A/B)<<endl;
    return 0;
}