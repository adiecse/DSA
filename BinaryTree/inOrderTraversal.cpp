#include<iostream>
using namespace std;

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right);
}