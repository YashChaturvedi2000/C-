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

vector<int> rightview(Node* root){
    vector<int> v;
    if(!root) return v;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int c=q.size();
        v.push_back(q.front()->data);
        while(c--){
            Node* t=q.front();
            q.pop();
            if(t->right) q.push(t->right);
            if(t->left) q.push(t->left);
        }
    }
    return v;
}

int main()
{
    Node* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
    root->right->right->left = createNode(16);
    vector<int> res;
    res=rightview(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}