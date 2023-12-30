// #Approach1 2 while loop
// #Approach2 sort link list
// #Approach3 use maps. 
// last 2 approaches left
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

    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;   
        }
        cout<<"Memory is freed for the Node value"<<val<<endl;
    }

};
 
void print(Node* &head){
    Node* temp=head;
    while(temp !=NULL){
       cout<<temp->data<<" " <<endl;
       temp=temp->next;  
    }
}

Node* RemoveDup(Node* &head){
    Node* curr=head;
    Node* temp;
     
     while(curr!=NULL){
         Node* prev=curr;
         temp=curr->next;
         while(temp!=NULL){
             if(temp->data==curr->data){
                 Node* next=temp->next;
                 prev->next=next;
                 temp->next=NULL;
                 delete temp;
                 temp=next;
                 
             }else{
                 temp=temp->next;
                 prev=prev->next;
                }
            }
            curr=curr->next;
        }
        
        return head;
}
int main(){
    
    Node* first= new Node(5);
    Node* second= new Node(2);
    Node* third= new Node(2);
    Node* fourth=new Node(4);

    first->next=second;
    second->next=third;
    third->next=fourth;
    Node* head;
    head=RemoveDup(first);
    cout<<"printing the LL"<<endl;
    print(head);

}