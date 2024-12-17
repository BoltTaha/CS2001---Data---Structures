bool valid(Node* root)
{
    return isbst(root, INT_MIN, INT_MAX);
}

bool isbst(Node* root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    
    if (root->data > min && root->data < max)
    {
        bool left = isbst(root->left, min, root->data);  // Check left subtree
        bool right = isbst(root->right, root->data, max);  // Check right subtree
        return left && right;
    }
    else
    {
        return false;
    }
}
