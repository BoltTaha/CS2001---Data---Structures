bool check_strickly(Node* root)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }

    bool check = root->left != NULL && root->right != NULL;

    bool check1 = check_strickly(root->left);
    bool check2 = check_strickly(root->right);

    if(check && check1 && check2)
    {
        return true;
    }
    else{
        return false;
    }
}
