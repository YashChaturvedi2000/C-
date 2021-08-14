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


void topview(Node *root){
    vector<int> ans;
    if(!root) return;
    unordered_map<int,int> map;
    queue<pair<Node*,int>> q;
    int h=0;
    q.push(make_pair(root,0));
    while(!q.empty()){
        Node* t=q.front().first;
        int h=q.front().second;
        q.pop();
        if(!map[h]){
            map[h]=t->data;
        }
        if(t->left){
            q.push(make_pair(t->left,h-1));
        }               
        if(t->right){
            q.push(make_pair(t->right,h+1));
        }
    }

    for(auto x:map){
        cout<<x.second<<" ";
    }


}

int main()
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right=createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    topview(root);
    return 0;
}