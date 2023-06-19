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

void print(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
     
    }
}

int getLength(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void del(Node* &head, Node* &tail, int position){
    Node* curr;
    Node* temp=head;
    int posi=1;
    int len=getLength(head);
    cout<<len<<endl;
    cout<<"p"<<endl;

    if (head==NULL){
       cout<<"Can't delete the Node"<<endl;
       return;
    }
    
    if(position==1){
      curr=temp->next;
      head=curr;
      temp->next=NULL;
      delete temp;
      return; 
    }

    
    if(position==len){
        cout<<"ntered 1"<<endl;
        while(posi!=position-1){
            temp=temp->next;
            posi++;
        }
        curr=temp;
        temp=temp->next;
        curr->next=NULL;
        delete temp;
        tail=curr;
        print(head);
        return;
    }
    
    while(posi!=position-1){
        cout<<temp->data<<endl;;
        temp=temp->next;
        posi++;
        cout<<"entered"<<endl;
    }
    // cout<<temp->data<<endl;
    // cout<<temp->next->data<<endl;
    curr=temp;
    temp=curr->next;
    // cout<<curr->data<<endl;
    curr->next=temp->next;
    // cout<<temp->data<<endl;
    temp->next=NULL;
    delete temp;
    
        

}


int main(){

   
    Node* first= new Node(20);
    Node* second= new Node(30);
    Node* third= new Node(40);
    Node* fourth= new Node(50);
    Node* fifth= new Node(60);
    Node* sixth= new Node(70);
    Node* tail=sixth;
    Node* head=first;

    
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    // print(head);
    del(head,tail,4);
    print(head);

    
}