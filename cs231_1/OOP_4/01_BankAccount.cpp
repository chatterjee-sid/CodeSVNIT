#include<iostream>
using namespace std;

class account{
private:
    string name;
    long long int acno;
    string type;
    long int amount;
public:
    void assign(string, long long int, string, long int);
    void deposit(long int);
    void withdraw(long int);
    void display();
};

void account::assign(string a, long long int b, string c, long int d){
    name = a;
    acno = b;
    type = c;
    amount = d;
}
void account::deposit(long int a){
    amount += a;
    cout<<"Deposit Successful"<<endl;
}
void account::withdraw(long int a){
    long int x = min(amount,a);
    amount -= min(amount,a);
    cout<<"Withdrawn amount: "<<x<<endl;
}
void account::display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Amount: "<<amount<<endl;
    cout<<"---"<<endl;
}

int main(){
    account X;
    X.assign("Phoenix Wright",11223324309, "Savings", 950000);
    X.display();
    X.deposit(5000);
    X.display();
    X.withdraw(10000);
    X.display();
}