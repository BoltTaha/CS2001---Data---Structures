#include<iostream>

using namespace std;

class Node {
public:
    int info;
    Node* left;
    Node* right;

    Node(int data) {
        this->info = data;
        left = NULL;
        right = NULL;
    }
};
   bool check_bst(Node* root, int min, int max) {
    if (root == NULL) {
        return true; 
    }

    if (root->info<=min || root->info>=max)
     {
        return false;
    }

    bool left = check_bst(root->left, min, root->info);
    bool right = check_bst(root->right, root->info, max);

    return left && right;
}

bool is_bst(Node* root) {
    return check_bst(root, INT8_MIN, INT8_MAX);
}


 int count_nodes(Node* root)
 {
    if (root == nullptr) 
    return 0;

    return 1 + count_nodes(root->left) + count_nodes(root->right);
 }
  

Node* largestsubtree(Node* root, int& max_size) {
    if (root == nullptr) 
        return nullptr;

    int left_size = count_nodes(root->left);
    int right_size = count_nodes(root->right);
    int current_size = 1 + left_size + right_size;

    if (current_size > max_size) {
        max_size = current_size;
        return root;
    }


    Node* left_largest = largestsubtree(root->left, max_size);
    Node* right_largest = largestsubtree(root->right, max_size);

   if (count_nodes(left_largest) > count_nodes(right_largest)) {
        largest = left_largest;
    } else {
        largest = right_largest;
    }

    return largest;
}
int main(void) {
    // Hard-code the BST
    Node* root = new Node(30);          
    root->left = new Node(15);          
    root->right = new Node(50);         
    root->left->left = new Node(10);    
    root->left->right = new Node(20);   
    root->right->left = new Node(40);   
    root->right->right = new Node(60);  
    if(is_bst(root))
    {
       cout<<"BST "<<endl;
    }
    else{
        cout<<"Not a BST"<<endl;
    }
  // Node* largest = largestsubtree(root);
    return 0;
}

