#include <iostream>
#include <vector>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Helper function to calculate the right view
void rightViewHelper(TreeNode* root, int level, vector<int>& result) {
    if (root == NULL) return; // Base case: if the node is NULL, stop.

    // If this is the first node of the current level, add it to the result
    if (level == result.size()) {
        result.push_back(root->data);
    }

    // Recursively visit the right and left subtrees
    rightViewHelper(root->right, level + 1, result); // Visit the right subtree first
    rightViewHelper(root->left, level + 1, result);  // Then visit the left subtree
}

// Main function to get the right view
vector<int> rightView(TreeNode* root) {
    vector<int> result; // To store the right view
    rightViewHelper(root, 0, result); // Start traversal at level 0
    return result;
}

int main() {
    // Hardcoding a binary tree for demonstration
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Calculate and print the right view
    vector<int> result = rightView(root);
    cout << "Right view of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
