

// // Helper function to calculate the size of a subtree
// int calculateSize(Node* root) {
//     if (root == nullptr) return 0; // Base case: empty subtree has size 0
//     return 1 + calculateSize(root->left) + calculateSize(root->right); // Count root, left, and right nodes
// }

// // Function to find the largest subtree and its size
// int findLargestSubtree(Node* root, Node*& largestSubtree) {
//     if (root == nullptr) return 0;

//     // Calculate sizes of left and right subtrees
//     int leftSize = findLargestSubtree(root->left, largestSubtree);
//     int rightSize = findLargestSubtree(root->right, largestSubtree);

//     // Calculate size of the current subtree
//     int currentSize = 1 + leftSize + rightSize;

//     // Update the largest subtree if the current one is bigger
//     if (largestSubtree == nullptr || currentSize > calculateSize(largestSubtree)) {
//         largestSubtree = root;
//     }

//     return currentSize;
// }

