#include <bits/stdc++.h> 
/**********************************************************************

Following is the Binary Tree node structure already written:

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

**********************************************************************/
//Sum At kth Level
//https://www.codingninjas.com/codestudio/problems/kth-level_920333


int sumAtKthLevel(BinaryTreeNode<int>* root, int k){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    int lvl=1;
    int sum=0;
    if(q.front()==NULL){
        return -1;
    }
    while(!q.empty()){
        BinaryTreeNode<int>* temp=q.front();
        q.pop();
        if(temp!=NULL){
            //if(lvl==k){
            //    sum+=temp->data;
            //}
           // cout<<temp->data<<endl;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }else{
            if(!q.empty()){
                lvl++;
                q.push(NULL);
                 
            }
        }
        if(lvl==k){
            while (q.front() != NULL) {
                BinaryTreeNode<int> *front = q.front();
                q.pop();
                sum = front->data + sum;
            }
            break;
        }
        
    }
    return sum;
}