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

Node* sort012(Node* &head){
    Node* temp=head;
    Node* zerohead=new Node(-1);
    Node* onehead=new Node(-1);
    Node* twohead=new Node(-1);
    Node* temp1=zerohead;
    Node* temp2=onehead;
    Node* temp3=twohead;
    while(temp!=NULL){
        if(temp->data==0){
            Node * zeronode=new Node(temp->data);
            temp1->next=zeronode;
            temp1=temp1->next;
        }

        if(temp->data==1){
            Node * onenode=new Node(temp->data);
            temp2->next=onenode;
            temp2=temp2->next;
        }

        if(temp->data==2){
            Node * twonode=new Node(temp->data);
            temp3->next=twonode;
            temp3=temp3->next;
        }
        
        temp=temp->next;

    }
    head=zerohead->next;
    temp1->next=onehead->next;
    temp2->next=twohead->next;
    zerohead->next=NULL;
    onehead->next=NULL;
    twohead->next=NULL;
    delete zerohead;
    delete onehead;
    delete twohead;
    print(head);
    return head;


}


int main(){
    
    Node* f= new Node(1);
    Node* s= new Node(2);
    Node* t= new Node(1);
    Node* fo=new Node(0);
    Node* fi=new Node(2);
    Node* si=new Node(2);
    Node* se=new Node(0);
    Node* e=new Node(1);





    f->next=s;
    s->next=t;
    t->next=fo;
    fo->next=fi;
    fi->next=si;
    si->next=se;
    se->next=e;
    Node* start=sort012(f);
    cout<<"printing the LL"<<endl;
    print(start);

}