#include<iostream>
#include<queue>
#include<stack>
using namespace std;

#define MAX 100

class TreeNode{
public:
    int val;
    TreeNode* left, * right;
    TreeNode(){
        this->val = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int x){
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int x, TreeNode* l, TreeNode* r){
        this->val = x;
        this->left = l;
        this->right = r ;
    }
};

stack<TreeNode*> S;
queue<TreeNode*> Q;

void bfs(){
    while(!Q.empty()){
        TreeNode* X = Q.front();
        cout<<X->val<<' ';
        Q.pop();
        if(X->left) Q.push(X->left);
        if(X->right) Q.push(X->right);
    }
}

void dfs(){
    while((!S.empty())){
        TreeNode* X = S.top();
        cout<<X->val<<' ';
        S.pop();
        if(X->right) S.push(X->right);
        if(X->left) S.push(X->left);
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    if(root){
        cout<<"BFS: ";
        Q.push(root);
        bfs();
        cout<<endl;
        cout<<"DFS: ";
        S.push(root);
        dfs();
        cout<<endl;
    } else{
        cout<<"BFS: NULL"<<endl<<"DFS: NULL"<<endl;
    }
    return 0;
}