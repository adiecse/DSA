// #Approach1 make 3 link list with starting node -1 and append 0,1,2 while moving from head to tail of main LL and then removes nodes with -1 value
// #Approach2 value replace with 2 pointer swap(values) zero in the link and put them in starting
// #Approach3 think there is one
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
    if(head==NULL){
        cout<<"can't sort the linked list"<<endl;
        return NULL;
    }

    if(head->next==NULL){
        return head;
    }

    Node* temp=head;
    Node* zerohead=new Node(-1);
    Node* zerotail=zerohead;

    Node* onehead=new Node(-1);
    Node* onetail=onehead;

    Node* twohead=new Node(-1);
    Node* twotail=twohead;

    while(temp!=NULL){
        if(temp->data==0){
            Node * zeronode=new Node(0);
            zerotail->next=zeronode;
            zerotail=zerotail->next;
        }

        if(temp->data==1){
            Node * onenode=new Node(1);
            onetail->next=onenode;
            onetail=onetail->next;
        }

        if(temp->data==2){
            Node * twonode=new Node(2);
            twotail->next=twonode;
            twotail=twotail->next;
        }
        
        temp=temp->next;

    }


  if(zerohead->next!=NULL){
       head=zerohead->next;
       zerohead->next=NULL;
       delete zerohead;

      if(onehead->next!=NULL){
         zerotail->next=onehead->next;
         onehead->next=NULL;
         delete onehead;

         onetail->next=twohead->next;   
         twohead->next=NULL;
         delete twohead;

        }else{
         zerotail->next=twohead->next;
         twohead->next=NULL;
         delete twohead;

        }
    }else{

      if(onehead->next!=NULL){
         head=onehead->next;
         zerotail->next=onehead->next;
         onehead->next=NULL;
         delete onehead;

         onetail->next=twohead->next;   
         twohead->next=NULL;
         delete twohead;

        }else{
         head=twohead->next;
         zerotail->next=twohead->next;
         twohead->next=NULL;
         delete twohead;

        }
    }  
    

    
    return head;


}


int main(){
    
    Node* f= new Node(2);
    Node* s= new Node(0);
    Node* t= new Node(2);
    Node* fo=new Node(1);
    Node* fi=new Node(2);
    Node* si=new Node(0);
    Node* se=new Node(1);
    Node* e=new Node(2);

    f->next=s;
    s->next=t;
    t->next=fo;
    fo->next=fi;
    fi->next=si;
    si->next=se;
    se->next=e;


    Node* temp=NULL;
    Node* start=sort012(f);
    cout<<"printing the LL"<<endl;
    print(start);

}