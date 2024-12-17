#include <iostream>
#include <algorithm>
using namespace std;

// Definition of a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};
 
 void inorder_rec(TreeNode* root)
 {
     if(root == NULL)

     {
        return;}
     inorder_rec(root->left);

     cout<<root->data<<endl;
     inorder_rec(root->right);
 }

 void mirror(TreeNode*& root)
 { 
            if(root == NULL) return;

           TreeNode* temp = root->left;
           root->left = root->right;
           root->right = temp;

           mirror(root->left);
           mirror(root->right);  
 }

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout<<"Inorder Traversal "<<endl;
    inorder_rec(root);
    cout<<endl;

    mirror(root);
    inorder_rec(root);


    return 0;
}
