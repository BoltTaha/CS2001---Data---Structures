#include <iostream>
#include <algorithm>
using namespace std;

// Definition of a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};
 
 void inorder_rec(TreeNode* root)
 {
     if(root == NULL)

     {
        return;}
     inorder_rec(root->left);

     cout<<root->data<<endl;
     inorder_rec(root->right);
 }

 bool sym(TreeNode* left,TreeNode* right)
 {
    if(left == NULL && right == NULL)

    {
        return true;
    }

    if(right == NULL || right == NULL)
    {
        return false;
    }

   
    if(left->data != right->data)
    {
        return false;
    }

    bool hold1 = sym(left->left,right->right);
    bool hold2 = sym(left->right,right->left);

   
    return hold1 && hold2;


 }

  bool helper_sym(TreeNode* root)
  {
    if(root == NULL)
    {
        return true;
    }

    return sym(root->left,root->right);
  }

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(3);


    return ;
}