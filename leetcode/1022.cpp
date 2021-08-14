#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* root=new Node();
    if(!root){
        cout<<"Not enough memory";
        return NULL;
    }
    root->key=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

vector<int> inorder(Node* root){
    vector<int> v;
    if(root==NULL){
        return;
    }
    inorder(root->left);
    v.push_back(root->key);
    inorder(root->right);
    return v;

}

int main(){
    Node* root=new Node();
    root=newNode(1);
    root->left=newNode(0);
    root->right=newNode(1);
    root->left->left=newNode(0);
    root->left->right=newNode(1);
    root->right->left=newNode(0);
    root->right->right=newNode(1);
    vector<int> res=inorder(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}