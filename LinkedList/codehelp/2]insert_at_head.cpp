#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node* next;

   Node(int data){
    this->data=data;
    this->next=NULL;
   }

   Node(){
    this->data=0;
    this->next=NULL;
   }
};

void print(Node* &head){
   Node* temp=head;
   while(temp->data!=NULL){
     cout<<temp->data<<" ";
     temp=temp->next;
   } 
}


void insertAtHead(Node* &head, int d){
    Node* newNode=new Node(d);
    newNode->next=head;
    head=newNode;
    
}

int main(){
    Node* head=new Node(10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);
    insertAtHead(head,60);
    print(head);
}