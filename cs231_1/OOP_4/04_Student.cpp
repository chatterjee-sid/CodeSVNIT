#include<iostream>
using namespace std;

class student{
    string first;
    string last;
public:
    int rollno;
    float marks;
    void nameaccept(string);
    void assign(int,string,float);
    void display();
};

void student::nameaccept(string name){
    string s = "";
    for(char i: name){
        if(i==' '){
            first = s;
            s = "";
        } else{
            s += i;
        }
    }
    last = s;
}
void student::assign(int a, string b, float c){
    rollno = a;
    nameaccept(b);
    marks = c;
}
void student::display(){
    cout<<"Roll no. "<<rollno<<endl;
    cout<<"Name: "<<first<<' '<<last<<endl;
    cout<<"Percentage: "<<marks<<endl;
}

int main(){
    student X;
    X.assign(28,"Siddhartha Chatterjee",80.8);
    X.display();
}

