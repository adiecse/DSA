

Node* deleteMid(Node* head)
{
    // Your Code Here
    Node* slow=head;
    Node* fast=head;
    Node*prev;
    
    if(head==NULL){    //Edge case 1 when head is NULL
        return NULL;
    }
    if(head->next==NULL){  //Edge case 2 when LL contain only one element return NULL After deleting it
        delete head;
        return NULL;
    }
    
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
    }
    Node* next=slow->next;
    slow->next=NULL;
    delete slow;
    prev->next=next;
    
    return head;
}