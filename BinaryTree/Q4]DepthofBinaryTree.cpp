//max depth/height of binary Tree
//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

int height(Node* root){
  if(root==NULL){
    return 0;
  }

  int heightleft=height(root->left);
  int heightright=height(root->right);

  if(heightleft>heightright){
    return heightleft+1;
  }else{
    return heightright+1;
  }
}