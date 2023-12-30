void reversetheLinkedList(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    Node*forward;
    while(curr!=NULL){
       forward=curr->next;
       curr->next=prev;
       prev=curr;
       curr=forward
    }
    head=prev;
    return head;
    
}