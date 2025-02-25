#include<iostream>
using namespace std;

class EmployeeBasic{
protected:
    string name;
    int emp_id;
    char gender;
public:
    EmployeeBasic(string a, int b, char c){
        name = a;
        emp_id = b;
        gender = c;
    }
    void EmpInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Emp_id: "<<emp_id<<endl;
        cout<<"Gender: "<<gender<<endl;
    }
};

class DeptBasic{
protected:
    string DeptName;
    string Work;
    int deadline;
public:
    DeptBasic(string a, string b, int c){
        DeptName = a;
        Work = b;
        deadline = c;
    }
    void DeptInfo(){
        cout<<"Department: "<<DeptName<<endl;
        cout<<"Assigned work: "<<Work<<endl;
        cout<<"Time to complete work (in hours): "<<deadline<<endl;
    }
};

class Employee:  public EmployeeBasic, public DeptBasic{
public:
    Employee(string a, int b, char c, string d, string e, int f) : EmployeeBasic(a,b,c), DeptBasic(d,e,f){}
    void display(){
        EmpInfo();
        DeptInfo();
    }
};

int main(){
    Employee A("Wright",5695,'M',"Operations","Moderator HX Updates",20);
    A.display();
    return 0;
}