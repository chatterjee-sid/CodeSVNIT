//04. Implement a program that takes a string input and uses a DEQUE( doubly ended queue ) to
check if the string is a palindrome. The program should utilize the properties of a deque to
efficiently compare characters from both ends of the string.
#include<iostream>
using namespace std;
#define MAX 10
#define MIN -1
class DEqueue{
public:
    int frontptr;
    int rearptr;
    char val[MAX];
    DEqueue(){
        this->frontptr=MIN;
        this->rearptr=MIN;
    }
    void Fenqueue(char data){
        if(frontptr==MIN){
            if(rearptr==MAX-1){
                cout<<"Overflow"<<endl;
                return;
            } else{
                for(int i=rearptr;i>frontptr;i--){
                    val[i+1]=val[i];
                }
                rearptr++;
                frontptr++;
            }
        }
        val[frontptr--]=data;
    }
    void Renqueue(char data){
        if(rearptr==MAX-1){
            if(frontptr==MIN){
                cout<<"Overflow"<<endl;
                return;
            } else{
                for(int i=frontptr+1;i<rearptr;i++){
                    val[i-1]=val[i];
                }
                frontptr--;
            }
        }
        val[++rearptr]=data;
    }
    char dequeue(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return -1;
        }
        return val[++frontptr];
    }
    int isEmpty(){
        return rearptr==frontptr;
    }
};
int palindrome_check(DEqueue one, DEqueue two){
    while(!one.isEmpty()){
        if(one.dequeue()!=two.dequeue()){
            return 0;
        }
    }
    return 1;
}
int main(){
    string str;
    cout<<"Enter string: ";
    cin>>str;
    DEqueue actual, reversed;
    int i=0;
    while(str[i]!='\0'){
        actual.Renqueue(str[i]);
        reversed.Fenqueue(str[i]);
        i++;
    }
    if(palindrome_check(actual,reversed)){
        cout<<"The string is a plaindrome"<<endl;
    } else{
        cout<<"The string is not a palindrome"<<endl;
    }
}