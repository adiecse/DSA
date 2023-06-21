

/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{   
    Node* curr=head;
    Node* prev=NULL;
    Node*next;
    if(x==1){
      next=curr->next;
      curr->next=NULL;
      delete curr;
      head=next;
      return head;
    }
   
    
    int count=1;
    
    while(count<x){
        next=curr->next;
        prev=curr;
        curr=next;
        count++;
        
    }
    
    next=curr->next;
    curr->next=NULL;
    prev->next=next;
    delete curr;
    
    return head;
    
}