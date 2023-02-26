#include<iostream>
using namespace std;

void PreOrder(Node*root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    root->left=PreOrder(root->left);
    root->right=PreOrder(root->right);
} 