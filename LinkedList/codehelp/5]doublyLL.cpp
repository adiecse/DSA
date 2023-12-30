#include<iostream>
using namespace std;

class Node{
    public:
   int data;
   Node* next;
   Node* prev;

   Node(){
    this->data=0;
    this->next=NULL;
    this->prev=NULL;
   }

   Node(int data){
    this->data=data;
    this->next=NULL;
    this->prev=NULL;
   }

   ~Node(){
        int val = this->data;
        if(this->next !=NULL || this->prev!=NULL){
         this->next=NULL;
         this->prev=NULL;
        }
        cout<<"Memory is freed for value"<<val<<endl;
   }
};

void print(Node* &head){
    Node* temp=head;
    cout<<"entered"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int getLength(Node* &head){
    int len=0;
    Node* temp=head;
    if(head==NULL){
        return 0;
    }

    while(temp!=NULL){
       len++;
       temp=temp->next;
    }
    return len;

}

void insertAthead(Node* &head, Node* &tail,int data){
    Node* temp=head;
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    Node* newNode= new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void inserAttail(Node* &head, Node* &tail, int data){
    Node* temp=tail;
    if(tail==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    Node* newNode=new Node(data);
    tail->next=newNode;
    newNode->prev=tail;
    tail=tail->next;
}

void isnertAtposition(Node* &head, Node* &tail, int position, int data){

    int len=getLength(head);
    int ptr=1;
    Node* temp=head;
    Node* curr;
    //empty
    if(head==NULL){
        insertAthead(head,tail,data);
        return;
    }

    //starting
    if(position==1){
        insertAthead(head,tail,data);
        return;
    }
    //end
    if(position>len) {
       inserAttail(head,tail,data);
       return;
    }

    //mid
    while(ptr!=position-1){
        ptr++;
        temp=temp->next;
    }
    curr=temp;
    temp=temp->next;
    Node* newNode=new Node(data);
    newNode->prev=curr;
    curr->next=newNode;
    newNode->next=temp;
    temp->prev=newNode;


}

void del(Node* &head, Node* &tail, int position){
    int ptr=1;
    Node* temp=head;
    Node* curr;
    int len=getLength(head);
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }

    if(position==1){
        curr=temp->next;
        head=curr;
        curr->prev=NULL;
        temp->next=NULL;
        
        
        delete temp;
        return;
    }

    if(position==len){
        
        while(ptr!=position-1){
            temp=temp->next;
            ptr++;
        }
        curr=temp;
        tail=curr; //we can do withoutt using curr also
        temp=temp->next;
        curr->next=NULL;
        temp->prev=NULL;
        delete temp;
        return;
        
    }

    while(ptr!=position){
        temp=temp->next;
        ptr++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->prev=NULL;
    temp->next=NULL;
    delete temp;
    

}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAthead(head,tail,5);
    inserAttail(head, tail,10);
    inserAttail(head,tail,15);
    isnertAtposition(head,tail,1,11);
    isnertAtposition(head,tail,3,2);
    isnertAtposition(head,tail,7,16);
    print(head);
    cout<<endl;
    del(head,tail,1);
    print(head);
}
