#include<iostream>
#include<fstream>
using namespace std;

string operator+ (string a, string b){
    string c;
    ofstream out("test.txt");
    out << a << b;
    out.close();
    ifstream in("test.txt");
    in >> c;
    in.close();
    return c;
}

class StringConcat{
    string mystring;
public:
    void set(string a, string b){
        mystring = a + b;
    }
    void display(){
        cout<<mystring<<endl;
    }
};

int main(){
    StringConcat A;
    A.set("hello","world");
    A.display();
    return 0;
}