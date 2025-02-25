#include<iostream>
using namespace std;

class Employee{
protected:
    string name;
    int Emp_id;
    string Address;
    string mail_id;
    long long int mobile;
    double Base, DA, HRA, PF, SCF;
public:
    Employee(string a, int b,string c,string d,long long int e){
        name = a;
        Emp_id = b;
        Address = c;
        mail_id = d;
        mobile = e;
    }
    void slipsetter(){
        DA = 0.97*Base;
        HRA = 0.1*Base;
        PF = 0.12*Base;
        SCF = 0.001*Base;
    }
    void base_info(){
        cout<<"Emp_id: "<<Emp_id<<endl;
        cout<<"Emp_name: "<<name<<endl;
        cout<<"Address: "<<Address<<endl;
        cout<<"Mail_id: "<<mail_id<<endl;
        cout<<"Mobile: "<<mobile<<endl;
    }
    void generateslip(){
        double gross = Base + DA + HRA;
        double net = gross - PF - SCF;
        cout<<"Base Pay (BP): "<<Base<<endl;
        cout<<"DA: "<<DA<<endl;
        cout<<"HRA: "<<HRA<<endl;
        cout<<"Gross Salary: BP+DA+HRA: "<<gross<<endl;
        cout<<endl;
        cout<<"PF: "<<PF<<endl;
        cout<<"SCF: "<<SCF<<endl;
        cout<<"Net Salary: Gross Salary - PF - SCF: "<<net<<endl;
    }
};

class Programmer : public Employee{
public:
    Programmer(string a, int b,string c,string d,long long int e) : Employee(a,b,c,d,e){
        Base = 80000;
        slipsetter();
    }
    void information(){
        cout<<"Employe category: Programmer"<<endl;
        base_info();
        cout<<endl;
        generateslip();
        cout<<endl;
    }
};

class AsstProf : public Employee{
public:
    AsstProf(string a, int b,string c,string d,long long int e) : Employee(a,b,c,d,e){
        Base = 90000;
        slipsetter();
    }
    void information(){
        cout<<"Employe category: Assistant Professor"<<endl;
        base_info();
        cout<<endl;
        generateslip();
        cout<<endl;
    }
};

class AssoProf : public Employee{
public:
    AssoProf(string a, int b,string c,string d,long long int e) : Employee(a,b,c,d,e){
        Base = 100000;
        slipsetter();
    }
    void information(){
        cout<<"Employee category: Associate Professor"<<endl;
        base_info();
        cout<<endl;
        generateslip();
        cout<<endl;
    }
};

class Prof : public Employee{
public:
    Prof(string a, int b,string c,string d,long long int e) : Employee(a,b,c,d,e){
        Base = 120000;
        slipsetter();
    }
    void information(){
        cout<<"Employe category: Professor"<<endl;
        base_info();
        cout<<endl;
        generateslip();
        cout<<endl;
    }
};

int main(){
    Programmer programmer("Franky",203,"Water Seven Grand Line","superrfranky@onemail.com",9384823465);
    programmer.information();
    AsstProf asstprof("Usopp",643,"Syrup East Blue","godusopp@onemail.com",9843268423);
    asstprof.information();
    AssoProf assoprof("Robin",795,"Ohara West Blue","nico.robin@onemail.com",8076524596);
    assoprof.information();
    Prof prof("Jinbe",464,"Fishman Island Grand Line","jinbe10@onemail.com",7967485747);
    prof.information();
    return 0;
}