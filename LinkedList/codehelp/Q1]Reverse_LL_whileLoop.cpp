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

Node* reverseLL(Node* &prev, Node* &head){
    while(head!=NULL){
        Node* forward=head->next;
        head->next=prev;
        prev=head;
        head=forward;

    }
     return prev;
}


void print(Node* &head){
    Node* temp=head;
    while(temp !=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;  
    }
}
int main(){
    
    Node* first= new Node(1);
    Node* second= new Node(2);
    Node* third= new Node(3);
    Node* fourth=new Node(4);

    first->next=second;
    second->next=third;
    third->next=fourth;

    Node* prev=NULL;
    Node* head=first;
    
    head=reverseLL(prev,head);
    cout<<"printing the LL"<<endl;
    print(head);

}