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

int find_mid(Node* &head){
    Node* fast=head;
    Node* slow=head;

    while(fast!=NULL ||fast->next!=NULL){
        cout<<"entered 1"<<endl;
        fast=fast->next;
        cout<<"entered 2"<<endl;
        if(fast->next!=NULL){
            fast=fast->next;
            
            cout<<"left"<<endl;
        }
        slow=slow->next;
        cout<<"slow data"<<slow->data<<endl;
    }
   
    return slow->data;
}

int main(){
    
    Node* first= new Node(1);
    Node* second= new Node(2);
    Node* third= new Node(3);
    Node* fourth=new Node(4);
 
    cout<<"hello"<<endl;
    first->next=second;
    second->next=third;
    third->next=fourth;
    int mid=find_mid(first);
    cout<<"hello"<<endl;
    cout<<"printing the mid"<<mid <<endl;
    // print(first);

}