#include<iostream>
using namespace std;

void fun(const int);
void fun(float);
void fun(float*);
void fun(const char*);

int main(){
    const int i = 1;
    float j = 2.2;
    float *p = &j;
    const char a = 'G';
    const char *c = &a;
    fun(i);
    fun(j);
    fun(p);
    fun(c);
}

void fun(const int i){
    cout<<"The constant integer received is "<<i<<endl;
}

void fun(float i){
    cout<<"The float value received is "<<i<<endl;
}

void fun(float* a){
    cout<<"The float pointer received contains value "<<*a<<endl;
    cout<<"The address of this float value is "<<a<<endl;
}

void fun(const char* a){
    cout<<"The const char pointer received contains value "<<*a<<endl;
    cout<<"The address of this const char value is "<<a<<endl;
}