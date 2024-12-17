#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;       // Stores the data of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize the node
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Tree class definition
class BinaryTree {
private:
    Node* root;  // Root node of the tree

    // Helper function for inorder traversal
    void inorderHelper(Node* node) {
        if (node != nullptr) {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    // Helper function for pre-order traversal
    void preorderHelper(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }

    // Helper function for post-order traversal
    void postorderHelper(Node* node) {
        if (node != nullptr) {
            postorderHelper(node->left);
            postorderHelper(node->right);
            cout << node->data << " ";
        }
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Function to insert a new node with value into the tree
    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);  // Create root node if the tree is empty
        } else {
            insertHelper(root, value);
        }
    }

    // Recursive function to insert a new node in the binary tree
    void insertHelper(Node* node, int value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(value);  // Insert in the left subtree
            } else {
                insertHelper(node->left, value);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new Node(value);  // Insert in the right subtree
            } else {
                insertHelper(node->right, value);
            }
        }
    }

    // Function to perform inorder traversal
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    // Function to perform preorder traversal
    void preorder() {
        preorderHelper(root);
        cout << endl;
    }

    // Function to perform postorder traversal
    void postorder() {
        postorderHelper(root);
        cout << endl;
    }

    bool check_for_bst(Node* root)
    {
        if(root == NULL)
        {
            return true;
        }
          
          
        if(root->left == NULL || root->right == NULL)
        {
            return true;
        }

        bool condition = root->data > root->left->data && root->data < root->right->data;
        bool check1 = check_for_bst(root->left);
        bool check2 = check_for_bst(root->right);

        return condition && check1 && check2; 
    }
};

// Main function to test the BinaryTree
int main() {
    BinaryTree tree;

    // Insert nodes into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Perform different traversals
    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    return 0;
}
