#include<iostream>
using namespace std;

void PostOrder(Node* root){
    if(root==NULL){
        return;
    }

    root->left=PostOrder(root->left);
    root->right=PostOrder(root->right);
    cout<<root->data<<" ";


}