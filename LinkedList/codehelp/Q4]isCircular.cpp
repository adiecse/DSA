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
 
void print(Node* &head){
    Node* temp=head;
    while(temp !=NULL){
       cout<<temp->data<<" " <<endl;
       temp=temp->next;  
    }
}

bool isCircular(Node* &head){
    Node* temp=head->next;
    if(head==NULL){
        cout<<"linked List is empty"<<endl;
        return false;
    }
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==NULL){
        return false;
    }
    if(temp==head){
        return true;
    }
}
void isCircular2(Node* &head){
    Node* slow=head;
    Node * fast=head->next;

    while(fast!=NULL && fast!=head){
        fast=fast->next;
        if(fast!=NULL && fast!=head){
            fast=fast->next;
            slow=slow->next;
        }
    }
    if(fast==NULL){
        cout<<"Linked list is non circular"<<endl;
        return;
    }
    if(fast==head){
        cout<<"linked list is circular"<<endl;
        return;
    }
}

bool isCircular3(Node* &head){
    Node* slow=head;
    Node * fast=head;

    while(fast!=NULL ){
        fast=fast->next;
        if(fast!=NULL ){
            fast=fast->next;
            slow=slow->next;

        }

        if(fast==slow){
            return true;
        }
    }
    return false;
}


int main(){
    
    Node* head= new Node(1);
    Node* second= new Node(2);
    Node* third= new Node(3);
    Node* fourth=new Node(4);
    Node* fifth=new Node(5);
    Node* sixth=new Node(6);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=head;

    
    if(isCircular(head)){
        cout<<"linekd List is circular"<<endl;
    }else{
        cout<<"linked List is non circular"<<endl;
    }
    

    isCircular2(head);
    return 0;


    // cout<<"printing the LL"<<endl;
    // print(first);

}