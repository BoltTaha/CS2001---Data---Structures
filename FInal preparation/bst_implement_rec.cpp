#include <iostream>
#include <queue>
using namespace std;

class Tree {
public:
    int data;
    Tree* left;
    Tree* right;

    // Constructor
    Tree(int m) {
        this->data = m;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive Function to Build a Binary Tree
Tree* insert_in_bst_recursive(Tree* root) {
    cout << "Enter the data (-1 for no node): ";
    int data;
    cin >> data;

    // Base Case
    if (data == -1) {
        return nullptr;
    }

    // Create New Node
    root = new Tree(data);

    // Recursively Build Left and Right Subtrees
    cout << "Enter data for the left of " << data << endl;
    root->left = insert_in_bst_recursive(root->left);

    cout << "Enter data for the right of " << data << endl;
    root->right = insert_in_bst_recursive(root->right);

    return root;
}

// Level Order Traversal
void binary_tree_lvl_order(Tree* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Tree*> q;
    q.push(root);

    while (!q.empty()) {
        Tree* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != nullptr) {
            q.push(temp->left);
        }

        if (temp->right != nullptr) {
            q.push(temp->right);
        }
    }
    cout << endl;
}

// Insert into a Binary Search Tree (BST)
Tree* insert_bst(Tree* root, int data) {
    if (root == nullptr) {
        return new Tree(data);
    }

    if (data > root->data) {
        root->right = insert_bst(root->right, data);
    } else if (data < root->data) {
        root->left = insert_bst(root->left, data);
    }
    return root;
}

// Take Input for a BST
void take_input(Tree*& node) {
    cout << "Enter data for the BST (-1 to stop): ";
    int d;
    cin >> d;

    while (d != -1) {
        node = insert_bst(node, d);
        cin >> d;
    }
}
   int height(Tree* root)
   {
    if(root == NULL)
    {
        return 0;
    }
       return 1 + max(height(root->left),height(root->right));
   }
int main() {
    Tree* root = nullptr;

   
    
            // root = insert_in_bst_recursive(root);
            // cout << "Level Order Traversal of the Binary Tree: ";
            // binary_tree_lvl_order(root);
           

     
            take_input(root);
            cout << "Level Order Traversal of the BST: ";
           // binary_tree_lvl_order(root);
            cout<<"Hegiht of the bst tree is "<<height(root);
           
    
      // 8 5 2 7 1 -1
    return 0;
}
