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


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);


    return ;
}
// Definition of TreeNode
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to find the Lowest Common Ancestor (LCA)
TreeNode* findLCA(TreeNode* root, int p, int q) { 
    // Base case: If root is NULL or root matches one of the target nodes, return root
    if (root == NULL || root->data == p || root->data == q) {
        return root;
    }

    // Recurse into left and right subtrees
    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);

    // If both left and right are non-NULL, root is the LCA
    if (left != NULL && right != NULL) {
        return root;
    }

    // If one side is NULL, return the non-NULL side
    return (left != NULL) ? left : right;
}
