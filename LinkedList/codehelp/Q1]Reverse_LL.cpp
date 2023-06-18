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

Node* reverseLL(Node* &prev, Node* &curr){
    //base case
    if(curr==NULL){
        //LL reverse ho chuki hai
        return prev;
    }
    //1 case solved now rec. will take care
    Node* next=curr->next;
    curr->next=prev;
    return reverseLL(curr,next);
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
    Node* curr=first;
    
    Node* head=reverseLL(prev,curr);
    cout<<"printing the LL"<<endl;
    print(head);

}