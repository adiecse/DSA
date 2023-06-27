//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
Structure of the node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
  public:
    // your task is to complete this function
   
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        
        
        
        Node* temp1=head1;
        Node* temp2=head2;
        
        int count=0;
                while(temp1!=NULL){
                    if(temp2!=NULL){
                        
                        if(temp1->data+temp2->data ==x) {
                            count++;
                            temp1=temp1->next;
                            temp2=head2;
                        }else if(temp1->data+temp2->data !=x){
                            temp2=temp2->next;
                        }
                  
                    }else{
                        temp2=head2;
                        temp1=temp1->next;
                    }
                }
                return count;
           
        }
    
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* tail2 = NULL;
        struct Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}
// } Driver Code Ends