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

// Function to print the BST in Inorder Traversal (Left, Root, Right)
void inorderTraversal(Tree* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int sum_nodes(Tree* root)
{
    int x,y;

    if(root == NULL)
    {
        return 0;
    }
    x = sum_nodes(root->left);
    y = sum_nodes(root->right);

    return x + y + root->data;
}

int count_leaf(Tree* root)
{
    int x,y;
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right== NULL)
    {
        return 1;
    }


    x = count_leaf(root->left);
    y = count_leaf(root->right);
    return x+y;
}

// Main Function
int main() {
    Tree* root = nullptr; // Initialize the root as nullptr

    // Insert values into the BST
    root = insert_bst(root, 50);
    root = insert_bst(root, 30);
    root = insert_bst(root, 70);
    root = insert_bst(root, 20);
    root = insert_bst(root, 40);
    root = insert_bst(root, 60);
    root = insert_bst(root, 80);

    // Print the BST using Inorder Traversal
    // cout << "Inorder Traversal of the BST: ";
    // inorderTraversal(root);
    // cout << endl;
    cout<<"The sum is "<<count_leaf(root);

    return 0;
}
