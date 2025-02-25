#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream input("07_input.txt");
    ofstream output("07_output.txt");
    string word;
    while(input>>word){
        output<<word<<' ';
    }
    input.close();
    output.close();
    return 0;
}