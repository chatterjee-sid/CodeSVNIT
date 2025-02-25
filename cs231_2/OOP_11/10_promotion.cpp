#include<iostream>
using namespace std;

class Employee{
    string EID;
    int exp;
public:
    Employee(string eid, int exp){
        EID = eid;
        this->exp = exp;
    }
    void PromotionStatus(){
        if(exp>=5){
            cout<<"Employee "<<EID<<" is promoted"<<endl;
        } else{
            cout<<"Employee "<<EID<<" is not promoted"<<endl;
        }
    }
};

int main(){
    Employee A("E2311",4);
    Employee B("E9824",6);
    A.PromotionStatus();
    B.PromotionStatus();
    return 0;
}