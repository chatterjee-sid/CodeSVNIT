#include<iostream>
using namespace std;

class Student{
    string name, rollno, subject;
public:
    Student(string,string,string);
    void display();
};

int main(){
    string a,b,c;
    cout<<"Enter Name: ";
    getline(cin,a);
    cout<<"Enter roll no. ";
    getline(cin,b);
    cout<<"Enter course: ";
    getline(cin,c);
    Student S(a,b,c);
    S.display();
    return 0;
}

Student::Student(string n, string r, string c){
    name = n;
    rollno = r;
    subject = c;
}

void Student::display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Roll no. "<<rollno<<endl;
    cout<<"Subject: "<<subject<<endl;
}