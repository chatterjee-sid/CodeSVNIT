#include<iostream>
using namespace std;

class DB;
class DM{
    int m;
    int cm;
public:
    DM(int,int);
    friend DM DMadder(DM,DB);
    friend DB DBadder(DM,DB);
    void display();
};

class DB{
    int ft;
    int in;
public:
    DB(int,int);
    friend DM DMadder(DM,DB);
    friend DB DBadder(DM,DB);
    void display();
};

DM::DM(int a, int b){
    m = a;
    cm = b;
    m += (cm/100);
    cm %= 100;
}
DB::DB(int a, int b){
    ft = a;
    in = b;
    ft += (in/12);
    in %= 12;
}

void DM::display(){
    cout<<m<<"m "<<cm<<"cm"<<endl;
}
void DB::display(){
    cout<<ft<<"ft "<<in<<"in"<<endl;
}

DM DMadder(DM metric, DB british){
    int b_in = british.in + 12*british.ft;
    int b_cm =  b_in*2.54;
    int m_cm = metric.cm + 100*metric.m;
    int all_cm = b_cm + m_cm;
    DM result(all_cm/100,all_cm%100);
    return result;
}

DB DBadder(DM metric, DB british){
    int m_cm = metric.cm + 100*metric.m;
    int m_in = m_cm/2.54;
    int b_in = british.in + 12*british.ft;
    int all_in = m_in + b_in;
    DB result(all_in/12,all_in%12);
    return result;
}

int main(){
    DM metric(4,88);
    DB british(13,10);
    DB britishADD = DBadder(metric,british);
    DM metricADD = DMadder(metric,british);
    britishADD.display();
    metricADD.display();
}