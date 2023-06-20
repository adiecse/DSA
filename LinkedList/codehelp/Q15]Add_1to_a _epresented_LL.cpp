//#Most imp question. solve this question for adding two linked list
//#Most imp test case is adding 1 to node having data 9 only and thi single node.
//solve this question again
//User function template for C++

/* 

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

class Solution
{
    public:
    
    Node* revLL(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* next;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
    Node* addOne(Node *head) 
    {
        Node* temp=revLL(head);
        Node* curr=temp;
        int carry=1;
        while(curr!=NULL){
            if(carry!=0){
                int sum=carry+curr->data;
                int digit=sum%10;
                carry=sum/10;
                curr->data=digit;
                if(carry!=0 && curr->next==NULL){  // this imp condition is written because when u will add 1 to 9 in that special test case  answer became 10. means ur carry will be 1. but there no next node to put the value of carry.  so we will sue this condition to make that new node . make new node when there is no next node and carry is not equal to zero(imp if condition).
                    Node* newNode= new Node(0);
                    curr->next=newNode;
                    curr=curr->next;
                }else{
                   curr=curr->next; 
                }
                
            }else{
                break;
            }        
        }
        // return head of list after adding one
        Node* hed=revLL(temp);
        return hed;
    }
};