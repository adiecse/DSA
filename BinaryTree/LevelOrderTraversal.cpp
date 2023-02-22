#include<iostream>
using namespace std;
#include<stack>


void levelOrder(Node*root){
    queue<int> q;
    q.push(root);
    q.push(NULL);

    if(q.front()==NULL){
        return ;
    }

    while(!q.empty()){
        Node* temp=q.front();
        cout<<temp->data<<endl;
        q.pop();
        if(temp!=NULL){
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }else{
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }

}