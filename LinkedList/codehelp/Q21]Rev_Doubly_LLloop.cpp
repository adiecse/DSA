Node* reverseDLL(Node * head)
{
   Node* curr=head;
   Node* back=NULL;
   Node* forw;
   while(curr!=NULL){
       forw=curr->next;
       curr->next=back;
       curr->prev=forw;
       back=curr;
       curr=forw;
   }
   return back;
}
