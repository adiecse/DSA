// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node* next;
    Node* prev;
    
    Node(){
        this->data=NULL;
        this->next=NULL;
        this->prev=NULL;
    }
    
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    
    ~Node(){
        int temp=this->data;
        if(this->next!=NULL&& this->prev!=NULL){
            delete next;
            this->next=NULL;
            
        }
        
    }
    
};

void insertAtHead(Node* &head,int d,Node* tail){
    if(head==NULL){
        Node*temp=new Node(d);
        head=temp;
        tail=temp;
    }else{
       Node*temp=new Node(d);
       temp->next=head;
       head->prev=temp;
       temp->prev=head->prev;
       head=temp;
    }   
}

void insertAtTail(Node* &tail, int d){
    if(tail==NULL){
        Node* temp= new Node(d);
        tail=temp;
    }else{
       Node* temp= new Node(d);
       tail->next=temp;
       temp->prev=tail;
       tail=temp;
    }
    return;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    int cnt=1;
    Node*temp=head;
    
    if(position==1){
        insertAtHead(head,d,tail);
        return;
    }
    
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    
    if(temp->next==NULL){
        insertAtTail(tail,d);
    }else{
       Node* nodeToInsert= new Node(d);
       nodeToInsert->next=temp->next;
       nodeToInsert->prev=temp;
       temp->next->prev=nodeToInsert;
       temp->next=nodeToInsert;
       
    }
    return;   
    
    
}
void deleteNode(Node*head,int position){
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next->prev=temp->prev;
        temp->next=NULL; 
        delete temp;
        return;
    }else{  
       int cnt=1;
       Node*temp=head;
       while(cnt!=position){
           temp=temp->next;
           cnt++;
       }
       temp->prev->next=temp->next;
       temp->next->prev=temp->prev;
       temp->next=NULL;
       temp->prev=NULL;
       delete temp;
    }
    return;
}
void print(Node* &head, Node* &tail){
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    
    Node*temp=head;
    while(temp!=NULL){
        cout<<"data store is: " <<temp->data<<endl;
        temp=temp->next;
    }
    return;
}
int main() {
    Node*temp=new Node();
    Node*head=temp;
    Node*tail=temp;
    //use above fucntions to insert , delete things;
    return 0;
}