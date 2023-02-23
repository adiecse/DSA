// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node* next;
    
    Node(){
        this->data=NULL;
        this->next=NULL;
    }
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    
    ~Node(){
        int temp=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
            
        }
        
    }
    
};

void insertAtHead(Node* &head,int d){
    if(head==NULL){
        Node*temp=new Node(d);
        head=temp;
    }
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail, int d){
    if(tail==NULL){
        Node* temp= new Node(d);
        tail=temp;
    }
    
    Node* temp= new Node(d);
    tail->next=temp;
    tail=temp;
    
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    int cnt=1;
    Node*temp=head;
    
    if(position==1){
        insertAtHead(head,d);
    }
    
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
    }
    Node* nodeToInsert= new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
    
    
}
void deleteNode(Node*head,int position){
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }else{  
       int cnt=1;
       Node*current=head;
       Node* prev=NULL;
       while(cnt<position){
           prev=current;
           current=current->next;
       }
       prev->next=current->next;
       current->next=NULL;
       delete current;
    }
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
}
int main() {
    Node*temp=new Node(NULL);
    Node*head=temp;
    Node*tail=temp;
    //use above fucntions to insert , delete things;
    return 0;
}