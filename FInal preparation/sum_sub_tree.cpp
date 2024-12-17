#include <iostream>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Helper function to calculate subtree sums and count matches
int countSubtreesWithSum(TreeNode* root, int targetSum, int& count) {
    if (root == NULL) return 0; // Base case: no sum for NULL node

    // Recursively calculate the sum of the left and right subtrees
    int leftSum = countSubtreesWithSum(root->left, targetSum, count);
    int rightSum = countSubtreesWithSum(root->right, targetSum, count);

    // Calculate the total sum of the current subtree
    int subtreeSum = root->data + leftSum + rightSum;

    // Check if the current subtree's sum matches the target
    if (subtreeSum == targetSum) {
        count++; // Increment the count if it matches
    }

    return subtreeSum; // Return the sum of the current subtree
}

// Main function to count subtrees with the given sum
int countSubtrees(TreeNode* root, int targetSum) {
    int count = 0;
    countSubtreesWithSum(root, targetSum, count); // Call the helper function
    return count;
}

int main() {
    // Hardcoding a binary tree for demonstration
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);

    int targetSum = 6;
    cout << "Number of subtrees with sum " << targetSum << ": " << countSubtrees(root, targetSum) << endl;

    return 0;
}
