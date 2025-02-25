#include<iostream>
using namespace std;

class College{
public:
    string name;
    int code;
};

int main(){
    College S;
    S.name = "SVNIT Surat";
    S.code = 12345;
    cout<<"College name: "<<S.name<<endl;
    cout<<"College code: "<<S.code<<endl;
}