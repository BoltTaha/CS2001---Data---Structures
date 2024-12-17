#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Recursive function to count nodes where data equals sum of left and right children
void count_sum(Node* root, int &count) {
    if (root == nullptr) {
        return;  // Base case: if the node is NULL, return
    }

    // Only proceed if the node has both left and right children
    if (root->left != nullptr && root->right != nullptr) {
        // Check if the node's value equals the sum of its left and right children
        if (root->data == root->left->data + root->right->data) {
            count++;  // Increment the count if the condition is met
        }
    }

    // Recursively check the left and right subtrees
    count_sum(root->left, count);
    count_sum(root->right, count);
}

int main() {
    // Example tree:
    //         10
    //        /  \
    //       3    7
    //      / \     \
    //     1   2     3
    Node* root = new Node(10);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right->right = new Node(3);

    int count = 0;
    count_sum(root, count);

    cout << "Number of nodes where data equals the sum of left and right children: " << count << endl;
    
    return 0;
}
