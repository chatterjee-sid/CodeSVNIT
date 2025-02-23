/*
2. Write a program to implement binary tree. Perform the following operations:
a. Insert an element into a binary search tree.
b. Delete an element from a binary search tree.
c. Traverse the binary tree by in-order and display the nodes.
d. Traverse the binary tree by pre-order and display the nodes.
e. Traverse the binary tree by post-order and display the nodes
*/
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
class tree{
public:
    node* root = nullptr;
    void insertNode(int data){
        if(root==nullptr){
            root = new node(data);
        } else{
            node* cur = root;
            node* temp = new node(data);
            while(1){
                if(data<cur->data){
                    if(cur->left==nullptr){
                        cur->left = temp;
                        break;
                    } else{
                        cur = cur->left;
                    }
                } else{
                    if(cur->right==nullptr){
                        cur->right = temp;
                        break;
                    } else{
                        cur = cur->right;
                    }
                }
            }
        }
        cout<<"Insertion Successful"<<endl;
    }
    void deleteNode(int data){
        node* parent = nullptr;
        node* cur = root;
        int direction;

        if(root->data!=data){
            while(cur!=nullptr){
                if(data < cur->data){
                    parent = cur;
                    cur = cur->left;
                    direction = 0;
                } else if(data > cur->data){
                    parent = cur;
                    cur = cur->right;
                    direction = 1;
                } else{
                    if(cur->left == nullptr){
                        if(cur->right == nullptr){
                            if(direction){
                                parent->right = nullptr;
                            } else{
                                parent->left = nullptr;
                            }
                        } else{
                            if(direction){
                                parent->right = cur->right;
                            } else{
                                parent->left = cur->right;
                            }
                        }
                    } else{
                        if(cur->right == nullptr){
                            if(direction){
                                parent->right = cur->left;
                            } else{
                                parent->left = cur->left;
                            }
                        } else{
                            node* temp = cur->right;
                            if(direction){
                                parent->right = temp;
                            } else{
                                parent->left = temp;
                            }
                            while(temp->left!=nullptr){
                                temp = temp->left;
                            }
                            temp->left = cur->left;
                        }
                    }
                    cout<<"Deletion successful"<<endl;
                    return;
                }
            }
            if(cur==nullptr){
                cout<<"Given element does not exist in the tree"<<endl;
            }
        } else{
            if(root->left==nullptr){
                if(root->right==nullptr){
                    root = nullptr;
                } else{
                    root = root->right;
                }
            } else{
                if(root->right==nullptr){
                    root = root->left;
                } else{
                    node* temp = root->right;
                    while(temp->left!=nullptr){
                        temp = temp->left;
                    }
                    temp->left = root->left;
                }
            }
            cout<<"Deletion successful"<<endl;
            return;
        }
    }
    void displayPreOrder(node* cur){
        if(cur==nullptr){
            return;
        }
        cout<<cur->data<<' ';
        displayPreOrder(cur->left);
        displayPreOrder(cur->right);
    }
    void displayInOrder(node* cur){
        if(cur==nullptr){
            return;
        }
        displayInOrder(cur->left);
        cout<<cur->data<<' ';
        displayInOrder(cur->right);
    }
    void displayPostOrder(node* cur){
        if(cur==nullptr){
            return;
        }
        displayPostOrder(cur->left);
        displayPostOrder(cur->right);
        cout<<cur->data<<' ';
    }
};
int main(){
    tree BST;
    int choice = 0;
    while(1){
        cout<<"Menu"<<endl;
        cout<<"\t1. Insert"<<endl;
        cout<<"\t2. Delete"<<endl;
        cout<<"\t3. In Order Traversal"<<endl;
        cout<<"\t4. Pre Order Traversal"<<endl;
        cout<<"\t5. Post Order Traversal"<<endl;

        cout<<"\t0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1){
            int val;
            cout<<"Enter value to insert: ";
            cin>>val;
            BST.insertNode(val);
        } else if(choice==2){
            int val;
            cout<<"Enter value to delete: ";
            cin>>val;
            BST.deleteNode(val);
        } else if(choice==3){
            cout<<"In Order: ";
            BST.displayInOrder(BST.root);
            cout<<endl;
        } else if(choice==4){
            cout<<"Pre Order: ";
            BST.displayPreOrder(BST.root);
            cout<<endl;
        } else if(choice==5){
            cout<<"Post Order: ";
            BST.displayPostOrder(BST.root);
            cout<<endl;
        } else if(choice==0){
            cout<<"Thank You"<<endl;
            break;
        } else{
            cout<<"Invalid option"<<endl;
        }
    }
}