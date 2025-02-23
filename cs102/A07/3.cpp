//03. Write a program to implement stack using linked list.
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next=nullptr;
};
class LLstack{
public:
    Node* head=nullptr;
    Node* current;
    void LinkCreater(int data){
        head = new Node;
        head->data = data;
        current = head;
    }
    void LLpush(int data){
        if(head==nullptr){
            LinkCreater(data);
            return;
        }
        Node* temp = new Node;
        temp->data = data;
        current->next = temp;
        current = temp;
    }
    int LLpop(){
        if(head==nullptr){
            cout<<"Underflow"<<endl;
            return -1;
        }
        current = head;
        //Need to handle final pop case
        if(head->next==nullptr){
            Node* remove = head;
            int x = remove->data;
            head = nullptr;
            delete remove;
            return x;
        }
        while(current->next->next!=nullptr){
            current = current->next;
        }
        Node* remove = current->next;
        current->next = nullptr;
        int x = remove->data;
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
    LLstack S;
    while(1){
        cout<<"Menu"<<endl;
        cout<<"\t1. Push"<<endl;
        cout<<"\t2. Pop"<<endl;
        cout<<"\t0. Exit"<<endl;
        int choice;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            int data;
            cout<<"Enter data: ";
            cin>>data;
            S.LLpush(data);
        } else if(choice==2){
            cout<<"Dequeued element: "<<S.LLpop()<<endl;
        } else if(choice==0){
            cout<<"Thank you!"<<endl;
            break;
        } else{
            cout<<"Invalid option"<<endl;
        }
        S.displayer();
    }
    return 0;
}