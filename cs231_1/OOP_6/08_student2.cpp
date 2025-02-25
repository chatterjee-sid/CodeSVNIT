#include<iostream>
using namespace std;

class Student{
    string name, rollno, subject;
public:
    Student(string,string,string);
    void display();
};

string* pointerAllocator(string, string, string);
void pointerDisplay(string*);

int main(){
    string a,b,c;
    cout<<"Enter Name: ";
    getline(cin,a);
    cout<<"Enter roll no. ";
    getline(cin,b);
    cout<<"Enter course: ";
    getline(cin,c);
    cout<<"Class Method"<<endl;
    Student S(a,b,c);
    S.display();
    cout<<"Pointer Method"<<endl;
    string *ptr = pointerAllocator(a,b,c);
    pointerDisplay(ptr);
    delete ptr;
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

string* pointerAllocator(string n, string r, string c){
    string* ptr = new string[3];
    *ptr++ = n;
    *ptr++ = r;
    *ptr++ = c;
    for(int i=0;i<3;i++) ptr--;
    return ptr;
}

void pointerDisplay(string* s){
    cout<<"Name: "<<*s<<endl;
    cout<<"Roll no. "<<*(s+1)<<endl;
    cout<<"Subject: "<<*(s+2)<<endl;
}