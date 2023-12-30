//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

Node *deleteK(Node *,int);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int getMiddle(struct Node *head);

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        int K;
        cin>>K;
        Node *res = deleteK(head,K);
        Node *temp = res;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


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

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

Node* deleteK(Node *head,int K)
{
  //Your code here
  Node* curr=head;
  Node* next=curr;
  Node* prev;
  int count;
  
  if(K==1){
      while(head!=NULL){   //k jab 1 hoga tab har node delete karni padegi;
          next=head->next;
          head->next=NULL;
          delete head;
          head=next;
      }
      return NULL;
  }
  while(curr!=NULL){
      count=1;
       while(count!=K){
           count++;
           prev=curr;
           curr=curr->next;
           if(curr==NULL){   // total nodes 28 hai samzo k=16 hai . k 17 hote hi curr NULL ho jayega and segmentation fault aajayega kuki non valid node access karneka try akr rahe hai.
               break;
           }
       }
       if(curr==NULL){  //total nodes 27 hai and K 14 hai jaise hi while loop se bahar nikalenge k 28 hoga and ham unvalid noe access karneka try karenge and segmentation fault aajayega
           break;
       }
       if(curr->next!=NULL){
            next=curr->next;
            prev->next=next;
            curr->next=NULL;
            delete curr;
            curr=next;
       } else{               //total 28 nodes hai and K 14 hai aur jab 28th node  delete karenge tab usake aage NULL hoga vapas NOn valid node acess karenge ham curr=next karke as next to NULL hoga usake liye condition
           prev->next=NULL;
           delete curr;
           curr=NULL;
       }   
       
     
       curr=next;
  }
  return head;
}
