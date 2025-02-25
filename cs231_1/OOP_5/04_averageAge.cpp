#include<iostream>
using namespace std;

class Student{
public:
    string ID;
    int sem;
    int age;
    float CPI;
    Student(string a, int b, int c, float d) : ID(a), sem(b), age(c), CPI(d) {}
};

float ageAv(Student A, Student B){
    return (A.age + B.age)/2.0;
}

int main(){
    Student A("23BCS092",3,18,7.8);
    Student B("23BCS044",3,21,8.2);
    cout << ageAv(A,B) << endl; 
}