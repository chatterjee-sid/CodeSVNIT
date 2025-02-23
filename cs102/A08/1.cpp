/*
1. Write a program to create a doubly linked list and perform the following operations:
a) Insert in beginning
b) Insert at last
c) Insert at any random location
d) Delete from Beginning
e) Delete from last
f) Delete node after specified location
g) Search for an element
h) Exit
*/
#include<iostream>
using namespace std;
class node{
public:
node* prev;
int data;
node* next;
};
class DLL{
public:
    node* head = nullptr;
    node* tail;
    void initiater(int data){
        head = new node();
        head->prev = nullptr;
        head->next = nullptr;
        head->data = data;
        tail = head;
        cout<<"Task successful"<<endl;
    }
    void rearInsert(int data){
        if(head==nullptr){
            initiater(data);
            return;
        }
        node* temp = new node();
        temp->prev = tail;
        temp->next = nullptr;
        temp->data = data;
        tail->next = temp;
        tail = temp;
        cout<<"Task successful"<<endl;
    }
    void frontInsert(int data){
        if(head==nullptr){
            initiater(data);
            return;
        }
        node* temp = new node();
        temp->next = head;
        temp->prev = nullptr;
        temp->data = data;
        head = temp;
        cout<<"Task successful"<<endl;
    }
    void midInsert(int pos, int data){
        if(pos==1 or head==nullptr){
            frontInsert(data);
            cout<<"Front insertion"<<endl;
            return;
        }
        node* current = head;
        int i = 0;
        while(i < pos-2 && current->next!=nullptr){
            current = current->next;
            i++;
        }
        node* temp = new node();
        temp->data = data;
        temp->prev = current;
        temp->next = current->next;
        if(temp->next!=nullptr) current->next->prev = temp;
        current->next = temp;
        if(temp->next==nullptr){
            tail=temp;
            cout<<"End insertion"<<endl;
        }
        cout<<"Task successful"<<endl;
    }
    void frontDelete(){
        if(head==nullptr){
            cout<<"Underflow"<<endl;
            return;
        }
        node* remove = head;
        head = head->next;
        if(head!=nullptr) head->prev = nullptr;
        else tail = nullptr;
        free(remove);
        cout<<"Task successful"<<endl;
    }
    void rearDelete(){
    if(tail==nullptr){
        cout<<"Underflow"<<endl;
        return;
    }
    node* remove = tail;
    tail = tail->prev;
    if(tail!=nullptr) tail->next = nullptr;
    else head = nullptr;
    free(remove);
    cout<<"Task successful"<<endl;
    }
    void midDelete(int pos){
        if(head==nullptr){
            cout<<"Underflow"<<endl;
            return;
        }
        if(pos==1 || head->next==nullptr){
            frontDelete();
            return;
        }
        node* current = head;
        int i = 0;
        if(head->next==nullptr){
            node* remove = head;
            head = nullptr;
            free(remove);
        }
        while(i<pos-2 && current->next->next!=nullptr){
            current = current->next;
            i++;
        }
        node* remove = current->next;
        if(current->next->next!=nullptr){
            current->next->next->prev = current;
        }
        current->next = current->next->next;
        free(remove);
        if(current->next == nullptr) tail = current;
        cout<<"Task successful"<<endl;
    }
    void search(int data){
        int pos = 0, flag = 0;
        node* current = head;
        while(current!=nullptr){
            pos++;
            if(current->data == data){
                flag = 1;
                break;
            }
            current = current->next;
        }
        if(flag){
            cout<<"Given data found at"<<endl;
            cout<<"\tNode No. "<<pos<<endl;
            cout<<"\tLocation: "<<current<<endl;
        } else{
            cout<<"Given data not found"<<endl;
        }
    }
    void display(){
        if(head!=nullptr){
            node* current = head;
            while(current!=nullptr){
                cout<<current->data<<' ';
                current=current->next;
            }
        }
        cout<<endl;
    }
};
int main(){
    DLL one;
    int num_nodes;
    cout<<"Enter number of nodes in the linked list: ";
    cin>>num_nodes;
    for(int i=0;i<num_nodes;i++){
        int data;
        cout<<"Enter data in node "<<i+1<<": ";
        cin>>data;
        one.rearInsert(data);
    }
    while(1){
        cout<<"DLL: ";
        one.display();
        cout<<"Menu"<<endl;
        cout<<"\t1. Insert at beginning"<<endl;
        cout<<"\t2. Insert at last"<<endl;
        cout<<"\t3. Insert at any random location"<<endl;
        cout<<"\t4. Delete from beginning"<<endl;
        cout<<"\t5. Delete from last"<<endl;
        cout<<"\t6. Delete node after specified location"<<endl;
        cout<<"\t7. Search for an element"<<endl;
        cout<<"\t0. Exit"<<endl;
        int choice;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1 || choice==2 || choice==3){
            int data;
            cout<<"Enter data to insert: ";
            cin>>data;
            if(choice==1) one.frontInsert(data);
            else if(choice==2) one.rearInsert(data);
            else if(choice==3){
                int pos;
                cout<<"Enter position: ";
                cin>>pos;
                one.midInsert(pos,data);
            }
        }
        else if(choice==4) one.frontDelete();
        else if(choice==5) one.rearDelete();
        else if(choice==6){
            int pos;
            cout<<"Enter position: ";
            cin>>pos;
            one.midDelete(pos);
        }
        else if(choice==7){
            int data;
            cout<<"Enter data to search: ";
            cin>>data;
            one.search(data);
        }
        else if(choice==0){
            cout<<"Thank you."<<endl;
            break;
        }
        else{
            cout<<"Invalid choice."<<endl;
        }
    }
}