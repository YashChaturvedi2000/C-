#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};

Node* newNode(int key){
    Node* root = new Node();
    if(!root){
        cout<<"Not enough memory";
        return NULL;
    }
    root->key = key;
    root->left=NULL;
    root->right=NULL;
    return root;
}

void inorderusingstack(Node* root){
    stack<Node*> s;
    Node* curr=root;
    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

int main()
{
    Node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    inorderusingstack(root);
}