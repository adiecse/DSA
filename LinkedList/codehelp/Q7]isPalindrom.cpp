// #Approach1 copy the linked list to array and use array method to find it is palindrom or nor
// #Approach2 did below


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
void print(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
     
    }
}

Node* find_mid(Node* &head){
   Node* slow=head;
   Node* fast=head; //if u don head->next as fast. then it will give second mid node n even number of LL

   while(fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
   }
   return slow;

}
Node* revLL(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}
bool is_palindrome(Node* &head){
    Node* mid= find_mid(head); 
    Node* temp1=mid->next;
    mid->next=revLL(temp1); //reversing LL after the mid 
    Node* temp=head;
    Node* temp2=mid->next;
    while(temp2!=NULL){
        if(temp->data != temp2->data){
            return false;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    print(head);
    cout<<endl;
    return true;
}




int main(){

    Node* head=new Node(1);
    Node* first= new Node(2);
    Node* second= new Node(2);
    Node* third= new Node(1);
    // Node* fourth= new Node(1);
    
    // Node* tail=sixth;

    head->next=first;
    first->next=second;
    second->next=third;
    // third->next=fourth;
    
    

    if(is_palindrome(head)){
        cout<<"yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    print(head);

    
}