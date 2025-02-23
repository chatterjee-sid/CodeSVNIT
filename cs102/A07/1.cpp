//01. Write a program to reverse the element of singly linked list.
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next=nullptr;
};
class singlyLinkedList{
public:
    Node* head=nullptr;
    Node* current;
    void LinkCreater(int data){
        head = new Node;
        head->data = data;
        current = head;
    }
    void LinkExtender(int data){
        if(head==nullptr){
            LinkCreater(data);
            return;
        }
        Node* temp = new Node;
        temp->data = data;
        current->next = temp;
        current = temp;
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
singlyLinkedList LinkReverse(singlyLinkedList& A){
    singlyLinkedList B;
    while(A.head->next!=nullptr){
        Node* current = A.head;
        while(current->next->next!=nullptr){
            current=current->next;
        }
        B.LinkExtender(current->next->data);
        Node* remove = current->next;
        current->next = nullptr;
        delete remove;
    }
    B.LinkExtender(A.head->data);
    delete A.head;
    return B;
}
int main(){
    singlyLinkedList L;
    int cnt;
    cout<<"Enter number of elements: ";
    cin>>cnt;
    for(int i=0;i<cnt;i++){
    cout<<"Enter element "<<i+1<<": ";
    int data;
    cin>>data;
    L.LinkExtender(data);
    }
    cout<<"Original List: ";
    L.displayer();
    singlyLinkedList M = LinkReverse(L);
    cout<<"Reversed List: ";
    M.displayer();
    return 0;
}