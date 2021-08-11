#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data){
    struct Node* root=new Node();
    if(!root){
        cout<<"Memory not allocated";
        return NULL;
    }
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;    
}

void inorder(Node *temp){
    if(temp==NULL){
        return;
    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}


int main()
{
        struct Node* root = newNode(10);
        root->left = newNode(11);
        root->left->left = newNode(7);
        root->left->right = newNode(12);
        root->right = newNode(9);
        root->right->left = newNode(15);
        root->right->right = newNode(8);
        
}