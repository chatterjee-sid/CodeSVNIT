//02. Write a program to implement queue using linked list.
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next=nullptr;
};
class LLqueue{
public:
    Node* head=nullptr;
    Node* current;

    void LinkCreater(int data){
        head = new Node;
        head->data = data;
        current = head;
    }
    void LLenqueue(int data){
        if(head==nullptr){
            LinkCreater(data);
            return;
        }
        Node* temp = new Node;
        temp->data = data;
        current->next = temp;
        current = temp;
    }
    int LLdequeue(){
        if(head==nullptr){
            cout<<"Underflow"<<endl;
            return -1;
        }
        Node* remove = head;
        int x = remove->data;
        head = head->next;
        delete remove;
        return x;
    }
    void displayer(){
        Node* show=head;
        while(show!=nullptr){
            cout<<show->data<<' ';
            show = show->next;
        }
        cout<<endl;
    }
};
int main(){
    LLqueue Q;
    while(1){
        cout<<"Menu"<<endl;
        cout<<"\t1. Enqueue"<<endl;
        cout<<"\t2. Dequeue"<<endl;
        cout<<"\t0. Exit"<<endl;
        int choice;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            int data;
            cout<<"Enter data: ";
            cin>>data;
            Q.LLenqueue(data);
        } else if(choice==2){
            cout<<"Dequeued element: "<<Q.LLdequeue()<<endl;
        } else if(choice==0){
            cout<<"Thank you!"<<endl;
            break;
        } else{
            cout<<"Invalid option"<<endl;
        }
        Q.displayer();
    }
}