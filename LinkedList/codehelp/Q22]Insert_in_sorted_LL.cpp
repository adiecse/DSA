class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node* prev=head;
        Node* curr=head->next;;
        if(head->data>data){
            // cout<<"entered"<<endl;
            Node* temp=new Node(data);
            temp->next=curr;
            head=temp;
            return head;
        }
        

        while(curr!=NULL){
          if(data>prev->data && data<curr->data){
              Node* temp=new Node(data);
              prev->next=temp;
              temp->next=curr;
              return head;
           }
           
           if(data>prev->data && data==curr->data){
              Node* temp=new Node(data);
              prev->next=temp;
              temp->next=curr;
              return head;
           }
           
           if(data>=prev->data && data<curr->data){
              Node* temp=new Node(data);
              prev->next=temp;
              temp->next=curr;
              return head;
           }
           
        //   if(data>prev->data && data==curr->data)
         
          prev=curr;
          curr=curr->next;
          
        }
        
        if(curr==NULL ){
            Node* temp=new Node(data);
            prev->next=temp;
            return head;
        }
    }
};