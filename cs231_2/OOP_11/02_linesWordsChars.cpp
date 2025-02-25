#include<iostream>
using namespace std;

int main(){
    cout<<"Enter input: ";
    char c;
    cin.get(c);
    int line = 0, word = 1, charac = 0;
    while(c!='\n'){
        charac += 1;
        if(c=='.' || c=='?' || c=='!'){
            line += 1;
        } else if(c==' '){
            word += 1;
        }
        cin.get(c);
    }
    if(charac==0){
        word = 0;
    }
    string type[4] = {"TYPE", "Characters", "Words", "Lines"};
    int values[3] = {charac,word,line};
    for(int i=0; i<4; i++){
        cout.width(11);
        cout.setf(ios::left, ios::adjustfield);
        cout<<type[i];
        if(i==0){
            cout<<"Count"<<endl;
            continue;
        }
        cout.unsetf(ios::left);
        cout.width(5);
        cout.setf(ios::right, ios::adjustfield);
        cout<<values[i-1]<<endl;
    }
    return 0;
}