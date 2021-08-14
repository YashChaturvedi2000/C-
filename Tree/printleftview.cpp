#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* root=new Node();
    if(!root){
        cout<<"Not enough memory";
        return NULL;
    }
    root->data=data;
    root->left=NULL;root->right=NULL;return root;
}

// void printLeft(Node* root){
//     if(root==NULL){
//         return;
//     }
//     cout<<root->data<<" ";
//     printLeft(root->left);
//     if(root->left==NULL && root->right!=NULL){
//         root=root->right;
//         cout<<root->data<<" ";
//     }
// }


vector<int> printLeft(Node* root){
    vector<int> v;
    if(!root) return v;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        v.push_back(q.front()->data);
        while(sz--){
            Node *t=q.front();
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
    return v;
}


int main()
{
    Node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);
    root->left->left->right=createNode(8);
    vector<int> res;
    res=printLeft(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}