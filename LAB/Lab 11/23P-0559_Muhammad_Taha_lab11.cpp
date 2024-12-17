#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        value = val;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree {
private:
    int getHeight(TreeNode* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    int getBalanceFactor(TreeNode* node) {
        return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    TreeNode* rotateRight(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    TreeNode* rotateLeft(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    TreeNode* getMinNode(TreeNode* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

public:
    TreeNode* insert(TreeNode* root, int value) {
        if (root == nullptr)
            return new TreeNode(value);

        if (value < root->value)
            root->left = insert(root->left, value);
        else if (value > root->value)
            root->right = insert(root->right, value);
        else
            return root;

        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

        int balance = getBalanceFactor(root);

        if (balance > 1 && value < root->left->value)
            return rotateRight(root);

        if (balance < -1 && value > root->right->value)
            return rotateLeft(root);

        if (balance > 1 && value > root->left->value) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && value < root->right->value) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    TreeNode* remove(TreeNode* root, int value) {
        if (root == nullptr)
            return root;

        if (value < root->value)
            root->left = remove(root->left, value);
        else if (value > root->value)
            root->right = remove(root->right, value);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                TreeNode* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            } else {
                TreeNode* temp = getMinNode(root->right);
                root->value = temp->value;
                root->right = remove(root->right, temp->value);
            }
        }

        if (root == nullptr)
            return root;

        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

        int balance = getBalanceFactor(root);

        if (balance > 1 && getBalanceFactor(root->left) >= 0)
            return rotateRight(root);

        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && getBalanceFactor(root->right) <= 0)
            return rotateLeft(root);

        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void displayInOrder(TreeNode* root) {
        if (root != nullptr) {
            displayInOrder(root->left);
            cout << root->value << " ";
            displayInOrder(root->right);
        }
    }
};

int main() {
    AVLTree tree;
    TreeNode* root = nullptr;

    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);
    root = tree.insert(root, 25);

    cout << "In-order traversal after insertions: ";
    tree.displayInOrder(root);
    cout << endl;

    root = tree.remove(root, 30);

    cout << "In-order traversal after deletion: ";
    tree.displayInOrder(root);
    cout << endl;

    return 0;
}
