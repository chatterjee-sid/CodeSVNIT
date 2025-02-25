#include<iostream>
using namespace std;

class Basic{
protected:
    string name;
    string rollno;
public:
    Basic(string a, string b){
        rollno = a;
        name = b;
    }
    void BasicInfo(){
        cout<<"Student ID: "<<rollno<<endl;
        cout<<"Name: "<<name<<endl;
    }
};

class Marks : public Basic{
protected:
    int OOP,DBMS,DAA,CO,DM;
public:
    Marks(string a, string b, int c, int d, int e, int f, int g) : Basic(a,b){
        OOP = c;
        DBMS = d;
        DAA = e;
        CO = f;
        DM = g;
    }
    void MarksDisplay(){
        BasicInfo();
        cout<<"OOP: "<<OOP<<endl;
        cout<<"DBMS: "<<DBMS<<endl;
        cout<<"DAA: "<<DAA<<endl;
        cout<<"CO: "<<CO<<endl;
        cout<<"DM: "<<DM<<endl;
    }
};

class Score : public Marks{
public:
    Score(string a, string b, int c, int d, int e, int f, int g) : Marks(a,b,c,d,e,f,g){};
    float percentage(){
        float sum = OOP+DBMS+DAA+CO+DM;
        return sum/5;
    }
    void display(){
        MarksDisplay();
        cout<<"Percentage: "<<percentage()<<endl;
    }
};

int main(){
    Score N("23CS1073","Wright",94,87,87,54,88);
    N.display();
    return 0;
}