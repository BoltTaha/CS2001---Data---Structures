#include <iostream>
#include <queue>
using namespace std;

// Node structure to represent a node in the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree class to handle tree operations
class BinarySearchTree {
private:
    Node* root;  // Root node of the BST

public:
    // Constructor: Initialize the tree
    BinarySearchTree() {
        root = nullptr;
    }

    // 1. Insert a node in the binary search tree
    void insert(int value) {
        root = insertRec(root, value);
    }

    // 2. Inorder Traversal: Left, Root, Right
    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    // 3. Preorder Traversal: Root, Left, Right
    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    // 4. Postorder Traversal: Left, Right, Root
    void postorder() {
        postorderRec(root);
        cout << endl;
    }

    // 5. Search a value in the BST
    bool search(int value) {
        return searchRec(root, value);
    }

    // 6. Find the minimum value in the BST
    int findMin() {
        Node* minNode = findMinRec(root);
        if (minNode != nullptr)
            return minNode->data;
        return -1; // indicates the tree is empty
    }

    // 7. Find the maximum value in the BST
    int findMax() {
        Node* maxNode = findMaxRec(root);
        if (maxNode != nullptr)
            return maxNode->data;
        return -1; // indicates the tree is empty
    }

    // 8. Delete a value from the BST
    void deleteValue(int value) {
        root = deleteRec(root, value);
    }

    // 9. Get the height of the tree
    int height() {
        return heightRec(root);
    }

    // 10. Find the inorder successor of a node
    Node* inorderSuccessor(Node* node) {
        return inorderSuccessorRec(node);
    }

    // 11. Find the inorder predecessor of a node
    Node* inorderPredecessor(Node* node) {
        return inorderPredecessorRec(node);
    }

    // 12. Check if the tree is balanced
    bool isBalanced() {
        return isBalancedRec(root);
    }

    // 13. Level Order Traversal (Breadth-First Search)
    void levelOrder() {
        levelOrderRec(root);
        cout << endl;
    }

    // 14. Count total number of nodes in the tree
    int countNodes() {
        return countNodesRec(root);
    }

    // 15. Kth Smallest Element
    int kthSmallest(int k) {
        int count = 0;
        return kthSmallestRec(root, k, count);
    }

    // 16. Kth Largest Element
    int kthLargest(int k) {
        int count = 0;
        return kthLargestRec(root, k, count);
    }

    // 17. Check if the tree is a valid Binary Search Tree
    bool isValidBST() {
        return isValidBSTRec(root, nullptr, nullptr);
    }

    // 18. Find Lowest Common Ancestor (LCA)
    Node* lowestCommonAncestor(Node* node1, Node* node2) {
        return lowestCommonAncestorRec(root, node1, node2);
    }

    // 19. Delete the entire tree
    void deleteTree() {
        root = deleteTreeRec(root);
    }

private:
    // Helper function to insert a node recursively
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    // Helper function for inorder traversal (Left, Root, Right)
    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    // Helper function for preorder traversal (Root, Left, Right)
    void preorderRec(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    // Helper function for postorder traversal (Left, Right, Root)
    void postorderRec(Node* node) {
        if (node != nullptr) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }

    // Helper function to search for a value recursively
    bool searchRec(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return searchRec(node->left, value);
        }

        return searchRec(node->right, value);
    }

    // Helper function to find the minimum node recursively
    Node* findMinRec(Node* node) {
        if (node == nullptr || node->left == nullptr) {
            return node;
        }
        return findMinRec(node->left);
    }

    // Helper function to find the maximum node recursively
    Node* findMaxRec(Node* node) {
        if (node == nullptr || node->right == nullptr) {
            return node;
        }
        return findMaxRec(node->right);
    }

    // Helper function to delete a node recursively
    Node* deleteRec(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteRec(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRec(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMinRec(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }

        return node;
    }

    // Helper function to calculate the height of the tree
    int heightRec(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = heightRec(node->left);
        int rightHeight = heightRec(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    // Helper function to check if the tree is balanced
    bool isBalancedRec(Node* node) {
        if (node == nullptr) {
            return true;
        }

        int leftHeight = heightRec(node->left);
        int rightHeight = heightRec(node->right);

        return abs(leftHeight - rightHeight) <= 1 && isBalancedRec(node->left) && isBalancedRec(node->right);
    }

    // Helper function for level order traversal (Breadth-First Search)
    void levelOrderRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
    }

    // Helper function to count the total number of nodes in the tree
    int countNodesRec(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodesRec(node->left) + countNodesRec(node->right);
    }

    // Helper function to find the kth smallest element (without using vectors)
    int kthSmallestRec(Node* node, int k, int &count) {
        if (node == nullptr) {
            return -1; // Return -1 if kth element is not found
        }

        // Check the left subtree first
        int leftResult = kthSmallestRec(node->left, k, count);
        if (leftResult != -1) {
            return leftResult;
        }

        // Increment count as we visit this node
        count++;

        // If the count matches k, return the current node's data
        if (count == k) {
            return node->data;
        }

        // Otherwise, check the right subtree
        return kthSmallestRec(node->right, k, count);
    }

    // Helper function to find the kth largest element (without using vectors)
    int kthLargestRec(Node* node, int k, int &count) {
        if (node == nullptr) {
            return -1; // Return -1 if kth element is not found
        }

        // Check the right subtree first
        int rightResult = kthLargestRec(node->right, k, count);
        if (rightResult != -1) {
            return rightResult;
        }

        // Increment count as we visit this node
        count++;

        // If the count matches k, return the current node's data
        if (count == k) {
            return node->data;
        }

        // Otherwise, check the left subtree
        return kthLargestRec(node->left, k, count);
    }

    // Helper function to check if the tree is a valid Binary Search Tree
    bool isValidBSTRec(Node* node, Node* low, Node* high) {
        if (node == nullptr) {
            return true;
        }

        if ((low != nullptr && node->data <= low->data) || (high != nullptr && node->data >= high->data)) {
            return false;
        }

        return isValidBSTRec(node->left, low, node) && isValidBSTRec(node->right, node, high);
    }

    // Helper function to find the lowest common ancestor (LCA)
    Node* lowestCommonAncestorRec(Node* node, Node* node1, Node* node2) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->data > node1->data && node->data > node2->data) {
            return lowestCommonAncestorRec(node->left, node1, node2);
        }

        if (node->data < node1->data && node->data < node2->data) {
            return lowestCommonAncestorRec(node->right, node1, node2);
        }

        return node;
    }

    // Helper function to delete the tree
    Node* deleteTreeRec(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        node->left = deleteTreeRec(node->left);
        node->right = deleteTreeRec(node->right);
        delete node;
        return nullptr;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(13);
    bst.insert(18);

    cout << "Inorder Traversal: ";
    bst.inorder();

    cout << "Preorder Traversal: ";
    bst.preorder();

    cout << "Postorder Traversal: ";
    bst.postorder();

    cout << "Search 15: " << (bst.search(15) ? "Found" : "Not Found") << endl;

    cout << "Minimum Value: " << bst.findMin() << endl;
    cout << "Maximum Value: " << bst.findMax() << endl;

    bst.deleteValue(10);
    cout << "Inorder Traversal after deletion: ";
    bst.inorder();

    cout << "Height of the tree: " << bst.height() << endl;

    cout << "Kth Smallest (3rd): " << bst.kthSmallest(3) << endl;
    cout << "Kth Largest (2nd): " << bst.kthLargest(2) << endl;

    cout << "Is Valid BST: " << (bst.isValidBST() ? "Yes" : "No") << endl;

    Node* node1 = bst.search(3) ? bst.getNode(3) : nullptr;
    Node* node2 = bst.search(7) ? bst.getNode(7) : nullptr;
    cout << "Lowest Common Ancestor of 3 and 7: " << bst.lowestCommonAncestor(node1, node2)->data << endl;

    bst.deleteTree();
    cout << "Tree after deletion (Inorder Traversal): ";
    bst.inorder();

    return 0;
}
