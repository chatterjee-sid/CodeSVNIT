//01. WAP to implement a queue data structure using 2 stacks
#include<iostream>
using namespace std;
#define MAX 10
#define MIN -1
class stack{
public:
    int top;
    int val[MAX];
    stack(){
        this->top=MIN;
    }
    void push(int data){
        if(this->top==MAX-1){
            cout<<"Overflow"<<endl;
            return;
        }
        this->val[++this->top]=data;
    }
    int pop(){
        if(this->top==MIN){
            cout<<"Underflow"<<endl;
            return -1;
        }
        return this->val[this->top--];
    }
        void display(){
            for(int i=0;i<=this->top;i++){
            cout<<this->val[i]<<' ';
        }
        cout<<endl;
    }
};
class queue{
public:
    stack actual,temporary;
    void enqueue(int data){
        (this->actual).push(data);
    }
    int dequeue(){
        while((this->actual).top>MIN+1){
            (this->temporary).push((this->actual).pop());
        }
        int x = (this->actual).pop();
        while((this->temporary).top>MIN){
            (this->actual).push((this->temporary).pop());
        }
        return x;
    }
    void display(){
        (this->actual).display();
    }
};
int main(){
    queue one;
    while(1){
        cout<<"Menu"<<endl;
        cout<<"\t1. Enqueue"<<endl;
        cout<<"\t2. Dequeue"<<endl;
        cout<<"\t0. Exit"<<endl;
        cout<<"Enter choice: ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to enqueue: ";
                int data;
                cin>>data;
                one.enqueue(data);
                break;
            case 2:
                cout<<"Popped element: "<<one.dequeue()<<endl;
                break;
            case 0:
                cout<<"Thank you!"<<endl;
                break;
            default:
                cout<<"Invalid option"<<endl;
        }
        if(!choice)
        break;
        cout<<"Queue as of now: "<<endl;
        one.display();
    }
}