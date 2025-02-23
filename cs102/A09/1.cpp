//1. Write a program to implement following Binary tree.
//1 (2 (4, 5), 3)
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* left = nullptr;
    node* right = nullptr;
    node(int data){
    this->data = data;
    }
};
class queue{
public:
    node* arr[100];
    int front;
    int rear;
    queue(){
        this->front = -1;
        this->rear = -1;
    }
    void Nqueue(node* add){
        if(front==-1){
            front = 0;
        }
        rear = (rear+1)%100;
        arr[rear]=add;
    }
    void Dqueue(){
        if(front==rear){
            front=-1;
            rear=-1;
        } else front = (front+1)%100;
    }
    void clear(){
        while(front!=-1){
            Dqueue();
        }
    }
};
class tree{
public:
    queue address;
    int nodes;

    tree(int nodes){
        this->nodes = nodes;
    }
    node* root = nullptr;
    void treeInsert(int data){
        if(root == nullptr){
            root = new node(data);
            address.Nqueue(root);
        } else{
            node* temp = new node(data);
            if(address.arr[address.front]->left == nullptr){
                address.arr[address.front]->left = temp;
            } else{
                address.arr[address.front]->right = temp;
                address.Dqueue();
            }
            address.Nqueue(temp);
        }
    }
    void displayBFS(){
        address.clear();
        int x;
        address.Nqueue(root);
        cout<<address.arr[address.front]->data<<' ';
        for(x=1;x<nodes;x++){
        if(address.arr[address.front]->left != nullptr){
        address.Nqueue(address.arr[address.front]->left);
        }
        if(address.arr[address.front]->right != nullptr){
        address.Nqueue(address.arr[address.front]->right);
        }
        address.Dqueue();
        cout<<address.arr[address.front]->data<<' ';
        }
        address.clear();
    }
};
int main(){
    tree* T = new tree(5);
    for(int i=1;i<=5;i++){
        T->treeInsert(i);
    }
    cout<<"BFS: ";
    T->displayBFS();
}