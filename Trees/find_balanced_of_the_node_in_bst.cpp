#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to calculate the height of a subtree
int height(Node* node) {
    if (node == nullptr) {
        return -1; // Base case: height of an empty tree is -1
    }
    
    // Recursively calculate the height of the left and right subtrees
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    // Return the greater of the two heights + 1 (for the current node)
    return max(leftHeight, rightHeight) + 1;
}

// Function to calculate the balance factor of a node
int balanceFactor(Node* node) {
    if (node == nullptr) {
        return 0; // A null node has a balance factor of 0
    }
    
    // Calculate the height of the left and right subtrees
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    // Return the balance factor (height of left subtree - height of right subtree)
    return leftHeight - rightHeight;
}

// Function to search for a node with a given value
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false; // Return false if root is null
    }
    
    if (root->data == value) {
        // If the node is found, print its balance factor
        cout << "Balance Factor of node with value " << value << ": " << balanceFactor(root) << endl;
        return true; // Node found, return true
    }
    
    // Recursively search in the left or right subtree based on the value
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    // Example Binary Search Tree (BST)
    //         10
    //        /  \
    //       5    15
    //      / \     \
    //     3   8    20
    
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->right = new Node(20);

    int valueToFind;
    cout << "Enter the value to search for: ";
    cin >> valueToFind;

    // Search for the node with the given value and calculate its balance factor
    bool found = search(root, valueToFind);

    // Check if the node was found
    if (!found) {
        cout << "Node with value " << valueToFind << " not found in the tree." << endl;
    }

    return 0;
}
