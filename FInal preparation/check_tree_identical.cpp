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

bool identical(Tree* root1, Tree* root2) {
    // Base Case: Both trees are empty
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // Base Case: One tree is empty, and the other is not
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Check current node's data and recursively check subtrees
    if (root1->data != root2->data) {
        return false;
    }

    bool hold1 = identical(root1->left, root2->left);
    bool hold2 = identical(root1->right, root2->right);

    return hold1 && hold2;
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
    cout << "Inorder Traversal of the BST: ";
    // inorderTraversal(root);
    // cout << endl;
    // 8 5 2 7 1 -1
 Tree* root2 = NULL;

   root2 = insert_bst(root2, 50);
    root2 = insert_bst(root2, 30);
    root2= insert_bst(root2, 70);
    root2 = insert_bst(root2, 20);
    root2 = insert_bst(root2, 40);
    root2 = insert_bst(root2, 10);
    root2 = insert_bst(root2, 80);

 if(identical(root,root2))
 {
    cout<<"The tree is identical"<<endl;

 }
 else{
    cout<<"Tree is not identical"<<endl;
 }
    
    return 0;
}



bool identical(Tree* root1, Tree* root2) {
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if(root1 == NULL && root2 != NULL)
    {
        return false;
    }

    if(root1 != NULL && root2 == NULL)
    {
        return false;
    }

    if(root1->data != root2->data)
    {
        return false;
    }

    bool hold1 = identical(root1->left,root2->left);
    bool hold2 = identical(root1->right,root2->right);

    return hold1&&hold2;
}
