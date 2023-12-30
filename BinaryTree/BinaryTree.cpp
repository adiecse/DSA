#include <iostream>
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
Node* BinaryTree(Node*root){
    int val;
    cout<<"enter data"<<endl;
    cin>>val;
    
    root=new Node(val);
    if(val==-1){
        return NULL;
    }
    
    cout<<"for inserting at left"<<" "; 
    root->left=BinaryTree(root->left);
    cout<<"for inserting at right"<<" ";
    root->right=BinaryTree(root->right);
    return root;
    
}
int main() {
    
    Node* temp=NULL;
    BinaryTree(temp);
    return 0;
}