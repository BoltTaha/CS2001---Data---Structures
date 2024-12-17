int kthsmallest(Node* root,int k)
{
    int i = 0;
    return solve(root,i,k);
}
int solve(Node* root,int& i,int k)
{
    if(root == NULL)
    {
        return -1;
    }
    int left = solve(root->left,i,k);     //l
    if(left!=k)
    {
        return left;
    }
   //n
    i++;

    if(i==k)
    {
        return root->data;
    }
//r
    return solve(root->right,i,k);
}