#include <iostream>
//#include "Bits/c++config.h"
#include<queue>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
  }

  //~Node(){
   // int value=this->data;
    //memory freeing
   // if(this->next!=NULL){
   //     delete next;
   //     this->next=NULL;
    //}
  //}

};

// Node* insertBST(Node* root, int val){
//     if(root==NULL){
//         return new Node(val);
//     }

//     if(val<root->data){
//         root->left=insertBST(root->left,val);
//     }else{
//         root->right=insertBST(root->right,val);
//     }
//     return root;
// }

Node* SearchinBST(Node*root , int key){
  if(root==NULL){
    return NULL;
  }
  if(key==root->data){
    return root;
  }
  if(key<root->data){
    return root->left;
  }
  //key>root->Data
  return root->right;
}

// void inOrder(Node*root){
//     if(root==NULL){
//         return ;
//     }

//     inOrder(root->left);
//     cout<<root->data<<" ";
//     inOrder(root->right);
// }

int main() {
  Node*root=NULL;
  root=insertBST(root,5);
  insertBST(root,1);
  insertBST(root,3);
  insertBST(root,4);
  insertBST(root,2);
  insertBST(root,7);
  
  //inOrder(root);
  Node*temp=SearchinBST(root,3);
  if(temp==NULL){
    cout<<"Key Not Found"<<endl;
  }else{
    cout<<"Key Found"<<endl;
  }
  return 0;
}