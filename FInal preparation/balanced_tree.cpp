#include <iostream>
using namespace std;

// Definition of the Tree Node
class Tree {
public:
    int data;
    Tree* left;
    Tree* right;

    // Constructor to initialize a node
    Tree(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a value into the BST
Tree* insert_bst(Tree* root, int data) {
    if (root == nullptr) {
        // Create a new node if the tree is empty
        return new Tree(data);
    }

    if (data < root->data) {
        // Insert into the left subtree
        root->left = insert_bst(root->left, data);
    } else if (data > root->data) {
        // Insert into the right subtree
        root->right = insert_bst(root->right, data);
    }
    // Return the unchanged root pointer
    return root;
}
// Function to find the height of the tree
int height(Tree* root)
{
    if (root == NULL) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

// Function to check if the tree is balanced
bool balanced(Tree* root)
{
    if(root == NULL)
    {
        return true;

    }

    bool hold1 = balanced(root->left);
    bool hold2 = balanced(root->right);

    bool hold3 = abs(height(root->left) - height(root->right)) <= 1;

    if(hold1 == true && hold2 == true && hold3 == true)
    {
        return true;
    }
    else{
        return false;
    }
}
