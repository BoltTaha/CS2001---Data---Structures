struct Node {
    int data;
    Node* left;
    Node* right;
};

bool findKthAncestor(Node* root, int target, int& k, int& ancestor) {
    if (!root) return false;

    // If target node is found
    if (root->data == target || 
        findKthAncestor(root->left, target, k, ancestor) || 
        findKthAncestor(root->right, target, k, ancestor)) {

        if (k > 0) k--; // Reduce k for each ancestor
        else if (k == 0) { // Found the kth ancestor
            ancestor = root->data;
            return false; // Stop further backtracking
        }
        return true;
    }
    return false;
}

int kthAncestor(Node* root, int target, int k) {
    int ancestor = -1;
    findKthAncestor(root, target, k, ancestor);
    return ancestor; // -1 if ancestor doesn't exist
}