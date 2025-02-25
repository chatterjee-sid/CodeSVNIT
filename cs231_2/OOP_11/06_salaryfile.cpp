#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int main(){
    ifstream input("06_input.txt");
    ofstream output("06_output.txt");
    string name;
    int age;
    float salary;
    while(input>>name>>age>>salary){        
        output<<name<<' '<<age<<' '<<fixed<<setprecision(2)<<salary*1.1<<'\n';
    }
    input.close();
    output.close();
    return 0;
}