// Online C++ compiler to run C++ program online
#include <iostream>
Node* inOrderSucc(Node* curr){
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

Node* deleteInBST(Node*root, int key){
    if(key<root->data){
        root->left=deleteInBST(root->left,key);
    }else if(key>root->data){
        root->right=deleteInBST(root->right,key);
    }else{
        if(root->left==NULL){
            Node*temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }else{
            Node*temp=inOrderSucc(root->right);
            root->data=temp->data;
            root->right=deleteInBST(root->right,temp->data);
        }
    }
}
