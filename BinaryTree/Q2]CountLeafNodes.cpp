/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
//Count Leaf Nodes
//https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055?


int noOfLeafNodes(BinaryTreeNode<int> *root){
   queue<BinaryTreeNode<int> *> q;
   q.push(root);
   q.push(NULL);
   int count=0;
   if(q.front()==NULL){
       return -1;
   }
   
   while(!q.empty()){
       BinaryTreeNode<int>* temp=q.front();
       q.pop();
       if(temp!=NULL){
           if(temp->left){
               q.push(temp->left);
           }
           if(temp->right){
               q.push(temp->right);
           }
           if(temp->left==NULL && temp->right==NULL){
               count++;
           }
       }else{
           if(!q.empty()){
               q.push(NULL);
           }
       }
   }
   return count;
}