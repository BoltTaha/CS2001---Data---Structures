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
 
 bool sum_tree(TreeNode* root)
{
    // Base case: NULL tree is a sum tree
    if (root == NULL)
    {
        return true;
    }
    
    // Base case: Leaf node is always valid
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    
    // Initialize the sum of children to 0
    int leftSum = 0, rightSum = 0;
    
    // Add left child's data if it exists
    if (root->left != NULL)
    {
        leftSum = root->left->data;
    }
    
    // Add right child's data if it exists
    if (root->right != NULL)
    {
        rightSum = root->right->data;
    }
    
    // Check if the current node satisfies the sum property
    if (root->data != leftSum + rightSum)
    {
        return false;
    }
    
    // Recursively check left and right subtrees
    return sum_tree(root->left) && sum_tree(root->right);
}



int main() {
    TreeNode* root = new TreeNode(9);
    root->left = new TreeNode(6);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

   if(sum_tree(root))
   {
    cout<<"The tree is sum Tree"<<endl;

   }
else
   cout<<"Not a sum tree"<<endl;
    


    return 0;
}
