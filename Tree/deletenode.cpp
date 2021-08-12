#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data){
    Node *root=new Node();
    if(!root){
        cout<<"No memory allocated";
        return NULL;
    }
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}
//function to delete deepest node
void deleteNode(Node *root, Node* d_node){
    queue<Node*> q;
    q.push(root);
    Node *temp;
    while(!q.empty()){
        temp=q.front();
        q.pop(); 
        if(temp==d_node){
            temp=NULL;
            delete(d_node);
            return;
        }
        if(temp->right){
            if(temp->right==d_node){
                temp->right=NULL;
                delete(d_node);
                return;
            }
            else{
                q.push(temp->right);
            }
        }
        if(temp->left){
            if(temp->left==d_node){
                temp->left=NULL;
                delete(d_node);
                return;
            }
            else{
                q.push(temp->left);
            }
        }
    }
}

//function to delete a node with given key

Node* deletion(Node* root, int key){
    Node *temp;
    Node *key_node=NULL;
    queue<Node*> q;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        if(root->data==key){
            return NULL; 
        }
        else{
            return root;
        }
    }

    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp->data==key){
            key_node=temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    if(key_node!=NULL){
        int x=temp->data;
        deleteNode(root,temp);
        key_node->data=x;
    }
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

int main(){
    Node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    inorder(root);
    root=deletion(root,4);
    cout<<endl;
    inorder(root);
    return 0;
}