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

int getLength(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
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

void insertAtPosition(Node* &head,int position,Node* &tail, int data){
    if(position==1){
        Node* newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        return;
    }

    int len=getLength(head);

    if(position>len){
       insertAtTail(tail,head,data);
       return;
    }

    int posi=1;
    Node*curr=head;
    Node* temp;
    while(posi!=position-1){
     curr=curr->next;
     posi++;
    }

    Node* newNode=new Node(data);
    temp=curr->next;
    curr->next=newNode;
    newNode->next=temp;



}


void print(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
     
    }
}

int main(){

    Node* head=new Node(10);
    Node* first= new Node(20);
    Node* second= new Node(30);
    Node* third= new Node(40);
    Node* fourth= new Node(50);
    Node* fifth= new Node(60);
    Node* sixth= new Node(70);
    Node* tail=sixth;

    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;

    insertAtPosition(head,8,tail, 25);
    print(head);

    
}