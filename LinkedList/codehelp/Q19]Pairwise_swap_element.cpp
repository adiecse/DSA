class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        Node* prev=NULL;
        Node*curr=head;
        Node* Cnext;
        Node* Nnext;
        while(curr!=NULL){
            if(prev!=NULL){
                if(curr->next!=NULL){
                    Cnext=curr->next;
                    Nnext=Cnext->next;
                    prev->next=Cnext;
                    Cnext->next=curr;
                    curr->next=Nnext;
                    prev=curr;
                    curr=Nnext;
                
                    if(Nnext!=NULL){
                     Cnext=Nnext->next;
                    }
                }else{
                    curr=curr->next;
                    
                }    
            }else{
                if(curr->next!=NULL){
                    Cnext=curr->next;
                    Nnext=Cnext->next;
                    // prev->next=Cnext;
                    curr->next=Nnext;
                    Cnext->next=curr;
                    prev=curr;
                    curr=Nnext;
                
                    head=Cnext;
                    if(Nnext!=NULL){
                     Cnext=Nnext->next;
                    }
                }else{
                    curr=curr->next;
                }        
                
                
            }    
            
        }
        return head;
    }
};