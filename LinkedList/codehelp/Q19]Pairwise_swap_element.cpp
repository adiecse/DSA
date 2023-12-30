//#MOst IMP question  //solve it atleast three time on GFG. 
// 5-6 edges are there  which u must handle them
//Try  to solve it by recursive approach also
//https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions
//#Solve this question in notebook also by writing the algorithm
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