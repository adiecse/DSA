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

void RemoveDup(Node* &head){
    cout<<"inside the function"<<endl;
    Node* curr=head;
    Node* prev=curr;
    curr=curr->next;

    while(curr!=NULL){
        cout<<"inside the while loop"<<endl;
        // Node* prev=curr;
        // curr=curr->next;
        if(prev->data==curr->data){
            cout<<"inside if"<<endl;
            Node* next=curr->next;
            curr->next=NULL;
            prev->next=next;
            delete curr;
            curr=next;
            // print(head);

        }else if(prev->data!=curr->data){
            cout<<"inside el if "<<endl;
            Node*next=curr->next;
            prev=curr;
            curr=next;
        }
    }
}
int main(){
    
    Node* first= new Node(1);
    Node* second= new Node(1);
    Node* third= new Node(2);
    Node* fourth=new Node(2);

    first->next=second;
    second->next=third;
    third->next=fourth;
    RemoveDup(first);
    cout<<"printing the LL"<<endl;
    print(first);

}