#include<iostream>
using namespace std;

int main(){
    string input = "";
    char ch;
    cin.get(ch);
    while(ch!='\n'){
        if(ch==' '){
            cout.put('_');
        } else{
            cout.put(ch);
        }
        cin.get(ch);
    }
    return 0;
}