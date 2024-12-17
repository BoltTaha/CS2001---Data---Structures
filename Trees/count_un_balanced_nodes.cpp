#include <iostream>
#include <algorithm> // For max function

using namespace std;

// Structure for a Binary Search Tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to calculate the height of the tree
int height(Node* node) {
    if (node == nullptr) {
        return 0;  // Base case: height of null is 0
    }

    // Recursively calculate the height of left and right subtrees
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    // Return the height of the current node (max of left and right heights + 1)
    return max(leftHeight, rightHeight) + 1;
}

// Recursive function to count unbalanced nodes in the BST
int countUnbalancedNodes(Node* root) {
    if (root == nullptr) {
        return 0;  // Base case: if the node is null, return 0
    }

    // Recursively count unbalanced nodes in left and right subtrees
    int leftCount = countUnbalancedNodes(root->left);
    int rightCount = countUnbalancedNodes(root->right);

    // Calculate the balance factor for the current node
    int currentBalance = height(root->left) - height(root->right);
    if (currentBalance < -1 || currentBalance > 1) {
        // If the node is unbalanced, add 1 to the count
        return leftCount + rightCount + 1;
    }

    // Otherwise, return the count of unbalanced nodes from both subtrees
    return leftCount + rightCount;
}

int main() {
    // Example binary search tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    // Count unbalanced nodes
    int unbalancedCount = countUnbalancedNodes(root);
    cout << "Number of unbalanced nodes: " << unbalancedCount << endl;

    return 0;
}
