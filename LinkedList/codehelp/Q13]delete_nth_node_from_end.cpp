// #https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    int getLength(Node* head){
        int count=0;
        Node* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    int getNthFromLast(Node *head, int n)
    {      
           if(head==NULL){
               return -1;
           }
           
           int len=getLength(head);
           if(n>len){
               return -1;
           }
           int N=(len-n)+1;
           Node* temp=head;
           int count=1;
           while(count!=N){
               count++;
               temp=temp->next;
           }
           return temp->data;
    };
};
