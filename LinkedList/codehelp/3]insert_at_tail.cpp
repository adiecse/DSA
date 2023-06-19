#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(){
    this->data=0;
    this->next=NULL;
  }

  Node(int data){
    this->data=data;
    this->next=NULL;
  }
};


void print(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
}

void insertAtHead(Node* &head,Node* &tail, int d){
   
    Node* newNode=new Node(d);
    newNode->next=head;
    if(head==NULL){ 
       tail=newNode;
    }
    head=newNode;

    
}

void insertAtTail(Node* &tail,Node* &head,int d){
   
    Node* newNode= new Node(d);
    if(tail==NULL){
        tail=newNode;
        head=newNode;
    }else{
        tail->next=newNode;
        tail=newNode;
    } 
    

}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    // Node* head= new Node(10);
    // Node* tail=head;
    insertAtTail(tail,head,60);
    insertAtHead(head,tail,90);
    insertAtHead(head,tail,100);
    insertAtTail(tail,head,40);
    insertAtHead(head,tail,110);
    insertAtHead(head,tail,120);
    insertAtTail(tail,head,50);
    insertAtHead(head,tail,130);
    insertAtHead(head,tail,140);
    insertAtTail(tail,head,20);
    insertAtTail(tail,head,30);
    
    
    

    //corner cases are when tail and head both are null means linked lsit is empty and we give command insert at tail or insert at head alone.
    
    print(head);

}