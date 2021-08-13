#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;Node *right;
};

Node* newNode(int data){
    Node* root=new Node();
    if(root==NULL){
        return NULL;
    }
    root->key=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

void okay(Node* root){
    Node* curr=root;
    Node* pre;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->key<<" ";
            curr=curr->right;
        }
        else{
            pre=curr->left;
            while(pre->right!=NULL && pre->right!=curr){
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }else{
                pre->right=NULL;
                cout<<curr->key<<" ";
                curr=curr->right; 
            }
        }
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

int main(){
    Node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    okay(root);
    return 0;
}