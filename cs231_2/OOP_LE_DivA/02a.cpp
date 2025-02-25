#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream in;
    char ch;
    in.open("02a_input.txt",ios::in);
    cout<<"The file will be appended by default:"<<endl;
    cout<<"Do you want it to be overwritten instead? (y/n)"<<endl;
    cin>>ch;
    ofstream out;
    if(ch=='y') out.open("02a_output.txt",ios::out);
    else out.open("02a_output.txt",ios::app);
    if(!in.is_open() || !out.is_open()){
        cout<<"File Opening Error Received"<<endl;
    } else{
        char c = in.get();
        while(in){
            out.put(c);
            c = in.get();
        }
        cout<<"File copied"<<endl;
    }
    return 0;
}