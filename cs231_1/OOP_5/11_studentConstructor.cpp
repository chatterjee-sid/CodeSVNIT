#include<iostream>
using namespace std;

class Student{
public:
    string ID;
    int sem;
    float CGPA;
    Student();
    Student(string);
    Student(string,int);
    Student(string,int,float);
    Student(Student&);
    void display();
};

Student::Student(){
    cout<<"Enter ID: ";
    cin>>ID;
    cout<<"Enter Sem: ";
    cin>>sem;
    cout<<"Enter CGPA: ";
    cin>>CGPA;
    cout<<"Added Successfully"<<endl;
    cout<<"---------------"<<endl;
}

Student::Student(string uid){
    ID = uid;
    cout<<"Enter Sem: ";
    cin>>sem;
    cout<<"Enter CGPA: ";
    cin>>CGPA;
    cout<<"Added Successfully"<<endl;
    cout<<"---------------"<<endl;
}

Student::Student(string uid, int semester){
    ID = uid;
    sem = semester;
    cout<<"Enter CGPA: ";
    cin>>CGPA;
    cout<<"Added Successfully"<<endl;
    cout<<"---------------"<<endl;
}

Student::Student(string uid, int semester, float CPI){
    ID = uid;
    sem = semester;
    CGPA = CPI;
    cout<<"Added Successfully"<<endl;
    cout<<"---------------"<<endl;
}

Student::Student(Student& stud){
    ID = stud.ID;
    sem = stud.sem;
    CGPA = stud.CGPA;
    cout<<"Added Successfully"<<endl;
    cout<<"---------------"<<endl;
}

void Student::display(){
    cout<<"UID: "<<ID<<endl;
    cout<<"Semester: "<<sem<<endl;
    cout<<"CGPA: "<<CGPA<<endl;
    cout<<"---------------"<<endl;
}

int main(){
    cout<<"Default Constructor"<<endl;
    Student A;
    A.display();
    cout<<"1 Argument Constructor"<<endl;
    Student B("U23CS028");
    B.display();
    cout<<"2 Argument Constructor"<<endl;
    Student C("U23CS028",3);
    C.display();
    cout<<"3 Argument Constructor"<<endl;
    Student D("U23CS028",3,9.33);
    D.display();
    cout<<"Copy Constructor"<<endl;
    Student E(A);
    E.display();
}