#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Person{
protected:
    string name, address;
    long long int phone_no;
public:
    Person(string a, string b, long long int c){
        name = a;
        address = b;
        phone_no = c;
    }
};

class Employee: public Person{
protected:
    int eno;
    string ename;
public:
    Employee(int a, string b, string c, long long int d) : Person(b,c,d){
        eno = a;
        ename = b;
    }
};

class Manager: public Employee{
protected:
    string desg, dept;
    int base_sal;
public:
    Manager(int a, string b, string c, string d, int e, string f, long long int g) : Employee(a,b,f,g){
        desg = c;
        dept = d;
        base_sal = e;
    }
    void display();
    friend void updater(Manager);
    bool operator > (Manager);
};

vector<Manager> MDetails;

void max_sal();

int main(){
    while(true){
        cout<<"Menu"<<endl;
        cout<<"\t1. Accept Manager details"<<endl;
        cout<<"\t2. Manager with highest salary"<<endl;
        cout<<"\t0. Exit"<<endl;
        int n;
        cout<<"Enter choice: ";
        cin>>n;
        if(n==1){
            string b,c,d,f;
            int a,e;
            long long int g;
            string temp;
            cout<<"Employee ID? ";
            cin>>a;
            cout<<"Name? ";
            getline(cin,temp);
            getline(cin,b);
            cout<<"Designation? ";
            getline(cin,c);
            cout<<"Department? ";
            getline(cin,d);
            cout<<"Salary? ";
            cin>>e;
            cout<<"Address? ";
            getline(cin,temp);
            getline(cin,f);
            cout<<"Phone no.? ";
            cin>>g;
            updater(Manager(a,b,c,d,e,f,g));
            cout<<"Data Accepted"<<endl;
        } else if(n==2){
            cout<<"Manager with highest Salary: "<<endl;
            max_sal();
        } else if(n==0){
            cout<<"Thank you"<<endl;
            break;
        } else{
            cout<<"Invalid operation"<<endl;
        }
    }
    return 0;
}

void Manager::display(){
    cout<<"Employee ID: "<<eno<<endl;
    cout<<"Manager name: "<<ename<<endl;
    cout<<"Designation: "<<desg<<endl;
    cout<<"Department: "<<dept<<endl;
    cout<<"Salary: "<<base_sal<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Phone no. "<<phone_no<<endl;
}

bool Manager::operator > (Manager X){
    if (base_sal > X.base_sal) return true;
    return false;
}

void updater(Manager X){
    for(int i=0;i<MDetails.size();i++){
        if (MDetails[i].eno == X.eno){
            MDetails[i] = X;
            return;
        }
    }
    MDetails.push_back(X);
}

void max_sal(){
    if(MDetails.empty()){
        cout<<"No Manager details"<<endl;
        return;
    }
    Manager max = MDetails[0];
    for(int i=0;i<MDetails.size();i++){
        if(MDetails[i] > max) max = MDetails[i];
    }
    max.display();
}