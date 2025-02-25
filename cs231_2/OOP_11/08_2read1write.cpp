#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream input;
    input.open("08_input1.txt");
    ofstream output;
    output.open("08_output.txt");
    char ch = input.get();
    while(input){
        output.put(ch);
        input.get(ch);
    }
    input.close();
    output.put(' ');
    input.open("08_input2.txt");
    ch = input.get();
    while(input){
        output.put(ch);
        input.get(ch);
    }
    input.close();
    output.close();
    return 0;
}