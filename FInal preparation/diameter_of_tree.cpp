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

// Helper function to calculate the height of the tree
int height(TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
}

// Function to calculate the diameter of the tree
int diameter(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

   int op1 = diameter(root->left);
   int op2 = diameter(root->right);
   int op3 = height(root->left) + height(root->right) + 2;
  
   int ans = max(op1,max(op2,op3));
   return ans;

}

// Example usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the tree: " << diameter(root) << endl;
    return 0;
}
