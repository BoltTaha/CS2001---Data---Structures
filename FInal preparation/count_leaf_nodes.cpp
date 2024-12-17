
void count_leaf(Node* root,int& count)
{
    if(root == NULL)
    {
        return ;
    }

    count_leaf(root->left,count);

    if(root->left == NULL && root->left == NULL)
    {
        count++;
    }

    count_leaf(root->right,count);
}




int helper_func(Node* root)
{
    int cnt = 0;
    count_leaf(root,count);
    return cnt;
}