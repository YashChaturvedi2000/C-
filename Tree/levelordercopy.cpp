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

int levelorder(Node *root){
    int sumodd=0;
    int sumeven=0;
    queue<Node*> q;
    q.push(root);
    int level=0;
    while(!q.empty()){
        int c=q.size();
        level++;
        while(c>0){
            Node* t=q.front();
            if(level%2==0){
                sumeven+=t->data;
            }
            else{
                sumodd+=t->data;
            }
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            c--;
        }
       
    }
    return sumodd-sumeven;
}


int main()
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(4);
    root->right = createNode(3);
    root->left->right=createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    vector<int> v;
    cout<<levelorder(root);
}
