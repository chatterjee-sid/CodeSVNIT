#include<iostream>
using namespace std;

class Employee{
protected:
    string name;
    int employeeID;
public:
    Employee(string name, int eid){
        this->name = name;
        employeeID = eid;
    }
    virtual void calculatePay() = 0;
};

class HourlyEmployee : public Employee{
    float hourpay;
    int hours;
public:
    HourlyEmployee(string name, int eid, float hourpay, int hours) : Employee(name, eid){
        this->hourpay = hourpay;
        this->hours = hours;
    }
    void calculatePay() override{
        cout<<"Employee name: "<<name<<endl;
        cout<<"Employee ID: "<<employeeID<<endl;
        cout<<"Pay per week: "<<hours*hourpay<<endl;
    }
};

class SalariedEmployee : public Employee{
    float salary;
public:
    SalariedEmployee(string name, int eid, float salary) : Employee(name, eid){
        this->salary = salary;
    }
    void calculatePay() override{
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee ID: "<<employeeID<<endl;
        cout<<"Pay per week: "<<salary/4<<endl;
    }
};

int main(){
    HourlyEmployee A("abc",1,10,25);
    A.calculatePay();
    SalariedEmployee B("def",2,10000);
    B.calculatePay();
    return 0;
}