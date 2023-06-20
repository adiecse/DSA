/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/


class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       Node* prev=del; //did istake here direct did Node* prev=head; galat aadat = head karneki
       Node*curr=prev->next;
       Node* next=curr->next;
       
       int dataa=prev->data; 
       prev->data=curr->data;
       curr->data=dataa;
       prev->next=next;
       curr->next=NULL;
       delete curr;
    }

};