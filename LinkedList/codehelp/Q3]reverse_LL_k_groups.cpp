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

void print(Node* &head){
    Node* temp=head;
    while(temp !=NULL){
       cout<<temp->data<<" " <<endl;
       temp=temp->next;  
    }
}

// Node* reverseLL(Node* &prev,Node* &head, Node* &forward){
//    Node* curr=head;
//    if(curr==forward){
//     return;
//    }

//    Node* next=curr->next;
//    curr->next=prev;
   
//    return reverseLL(curr,next,forward);
   

// }
// void groupRveLL(Node* &head,  int k){
//     int len=getLength(head);
//     Node* prev;

//     if(head==NULL){
//        cout<<"cant revrse the empty LL"<<endl;
//        return;
//     }

//     if(len==1){
//         cout<<"linked List contain only one node"<<endl;
//         return;
//     }

//     // if(k>len){
//     //     cout<<"Group size is greater than length of LL"<<endl;
//     //     return;
//     // }

//     int count=1;
//     Node* temp=head;
//     Node* curr=head;
//     Node* forward;

//     while(count!=k){
//         count++;
//         curr=curr->next;

//     }
//     forward=curr->next;
//     prev=NULL;
//     head=reverseLL(prev,temp,forward);
//     return groupRveLL(head, k);



// }

Node* revKNodes(Node* &head, int k){
    int len=getLength(head);

   if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return NULL;
    }

    if(len==1){
        return head;
    }

   if(len<k){
        cout<<"can't reverse the Linked list"<<endl;
        return head;
    }

    Node* prev=NULL;
    Node* curr=head;
    Node* next;
    int count=0;

    while(count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(next!=NULL){
        head->next=revKNodes(next,k);
    }

    return prev;
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
    
    // cout<<"printing the LL"<<endl;
    // print(first);
    Node* head=first;
    head=revKNodes(first,4);
    print(head);


}