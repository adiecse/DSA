// Online C++ compiler to run C++ program online
#include <iostream>
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

Node* reverseLL(Node* &prev, Node* &curr){
    //base case
    if(curr==NULL){
        //LL reverse ho chuki hai
        return prev;
    }
    //1 case solved now rec. will take care
    Node* next=curr->next;
    curr->next=prev;
    next= reverseLL(curr,next);
    return next;
}


int main() {
   Node * head=new Node(1);
   Node* tail=head;
   insertAtTail(tail,head,2);
   insertAtTail(tail,head,3);
   insertAtTail(tail,head,4);
   insertAtTail(tail,head,5);
   insertAtTail(tail,head,6);
   print(head);
   cout<<endl;
   Node* temp=head->next->next;
   Node* prev=head->next;
   Node* p=NULL;
   prev->next=reverseLL(p,temp);
   
   print(head);

    return 0;
    
    
    
}
