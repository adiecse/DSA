/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node* temp1=head1;
    Node* temp2=head2;
    Node* head3=new Node(-1);
    Node* temp=head3;
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data==temp2->data){
            Node* temp3=new Node(temp1->data);
            temp->next=temp3;
            temp=temp3;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        else if(temp1->data<temp2->data){
            temp1=temp1->next;
        }
        
        else if(temp1->data>temp2->data){
            temp2=temp2->next;
        }
    }
    
    Node* next=head3->next;
    head3->next=NULL;
    head3=next;
    
    return head3;
}