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

Node* Floyd_Cycle_Node_Deletion(Node* &head){
   Node* slow=head;
   Node* fast=head;

   while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        if(fast==slow){
            slow=head;
            break;
        }
   }
   
    if(fast==NULL){
        return NULL;
    }
    Node*prev=fast;
    while(fast!=slow){
        prev=fast;
        fast=fast->next;
        slow=slow->next;
    }

    prev->next=NULL;
    return head;
}

int main(){
    
    Node* first= new Node(1);
    Node* second= new Node(2);
    Node* third= new Node(3);
    Node* fourth=new Node(4);
    Node* fifth=new Node(5);
    Node* sixth=new Node(6);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=fifth;
    
    // // cout<<"printing the LL"<<endl;
    // // print(first);
    Node* head=first;
    Node* loop_Node=Floyd_Cycle_Node_Deletion(head);
    print(head);
    return 0;


}