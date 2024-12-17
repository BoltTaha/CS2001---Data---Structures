#include <iostream>
#include <vector>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Utility functions for boundary traversal
class BinaryTree {
public:
    Node* root;

    // Constructor
    BinaryTree() : root(NULL) {}

    // Create the tree
    void createTree() {
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);
        root->left->right->left = new Node(8);
        root->left->right->right = new Node(9);
    }


    void printlefttree(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return;

        }

        cout<<root->data<<" ";

        if(root->left != NULL)
        {
            printlefttree(root->left);

        }
        else
        {
            printlefttree(root->right);
        }
    }

    void print_leafnodes(Node* root)
    {
        if(root == NULL)
        {
            return ;
        }

        print_leafnodes(root->left);

        if(root->left == NULL && root->right == NULL)
        {
            cout<<root->data<<" ";
        }

        print_leafnodes(root->right);
    }

    void print_rightree(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left == NULL && root->left == NULL)
        {
            return;
        }
        if(root->right != NULL)
        {
            print_rightree(root->right);
        }
        else{
            print_rightree(root->left);
        }

        cout<<root->data<<" ";
    }
    void boundaryTraversal()
    {
        if(root == NULL)
        {
            return;
        }

        printlefttree(root);
        print_leafnodes(root);
        print_rightree(root->right);
    }

    

   

};

// Main function
int main() {
    // Create a binary tree
    BinaryTree tree;

    // Hardcode the tree structure
    tree.createTree();

    // Perform and display boundary traversal
    cout << "Boundary Traversal of the Tree: ";
    tree.boundaryTraversal();

    return 0;
}
