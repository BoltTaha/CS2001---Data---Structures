#include <iostream>
using namespace std;

// Definition of the tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal and store values in a fixed-size array
void inorderTraversal(Node* root, int elements[], int& count) {
    if (!root) return;

    // Traverse left subtree
    inorderTraversal(root->left, elements, count);

    // Store current node's data in the array
    elements[count++] = root->data;

    // Traverse right subtree
    inorderTraversal(root->right, elements, count);
}

// Function to find if there exist two nodes whose product equals k
bool findProduct(Node* root, int k) {
    if (!root || k <= 0) return false;

    int elements[100]; // Fixed-size array to store the elements
    int count = 0;

    // Perform inorder traversal to store BST elements in sorted order
    inorderTraversal(root, elements, count);

    // Two-pointer technique to find the pair with product k
    int left = 0, right = count - 1;

    while (left < right) {
        int product = elements[left] * elements[right];
        if (product == k) {
            return true; // Found a pair
        } else if (product < k) {
            left++; // Move left pointer
        } else {
            right--; // Move right pointer
        }
    }

    return false; // No such pair exists
}

// Main function
int main() {
    // Constructing example BST
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    // Example 1
    cout << (findProduct(root, 24) ? "true" : "false") << endl; // Output: true (6 * 4 = 24)
    cout << (findProduct(root, 2) ? "true" : "false") << endl;  // Output: false

    // Example 2
    Node* root2 = new Node(3);
    root2->right = new Node(5);
    cout << (findProduct(root2, 15) ? "true" : "false") << endl; // Output: true (3 * 5 = 15)

    return 0;
}
