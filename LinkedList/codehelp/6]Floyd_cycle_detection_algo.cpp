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
 


bool Floyd_Cycle_Detection(Node* &head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        slow=slow->next;
        if(fast!=NULL){
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
    
    // Node* first= new Node(1);
    // Node* second= new Node(2);
    // Node* third= new Node(3);
    // Node* fourth=new Node(4);
    // Node* fifth=new Node(5);
    // Node* sixth=new Node(6);

    // first->next=second;
    // second->next=third;
    // third->next=fourth;
    // fourth->next=fifth;
    // fifth->next=sixth;
    
    // // cout<<"printing the LL"<<endl;
    // // print(first);
    Node* head=first;
    ;


}