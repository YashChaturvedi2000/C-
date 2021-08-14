#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int data){
    Node *newNode = new Node();
    if(!newNode){
        cout<<"Memory allocation failed";
        return NULL;
    }
   
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    
    return newNode;
}

void levelorder(Node *root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* t=q.front();
        cout<<t->data<<" ";
        q.pop();
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
}

int main()
{
    Node* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
    vector<int> v;
    levelorder(root);
}
