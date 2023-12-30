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

Node* insertBST(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left=insertBST(root->left,val);
    }else{
        root->right=insertBST(root->right,val);
    }
    return root;
}

// void levelOrder(Node* root){
//     queue<int> q;
//     q.push(root);
//     q.push(NULL);

//     if(q.front==NULL){
//         return;
//     }

//     while(!q.empty()){
//         Node* temp=q.front();
//         cout<<temp->data<<endl;
//         q.pop();

//         if(temp!=NULL){
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }else{
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//     }

// }

void inOrder(Node*root){
    if(root==NULL){
        return ;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main() {
  Node*root=NULL;
  root=insertBST(root,5);
  insertBST(root,1);
  insertBST(root,3);
  insertBST(root,4);
  insertBST(root,2);
  insertBST(root,7);
  //insertBST(root,10);
  //insertBST(root,9);
  //insertBST(root,7);
  //inOrder(root);
  return 0;
}