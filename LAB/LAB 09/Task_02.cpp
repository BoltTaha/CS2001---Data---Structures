#include<iostream>
#include<stack>

using namespace std;

class Node{
    public:
    int info;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->info = data;
        left = NULL;
        right = NULL;
    }
};

Node* insert_in_bst_recursive(Node* root,int val)
{
   
    if(root == NULL)
    {    Node* new_Node = new Node(val);
        return new_Node;
    }

    if(root->info > val)
    {
        root->left = insert_in_bst_recursive(root->left,val);
        
    }
    else if(root->info < val)
    {
        root->right = insert_in_bst_recursive(root->right,val);
    }
    return root;
}



void display_in_order_traversing_recursive(Node* root)     //recursive
{
    if(root == NULL) return;

     display_in_order_traversing_recursive(root->left);
    cout<<root->info<<" ";
     display_in_order_traversing_recursive(root->right);
}

void take_input(Node* &root)
{
    cout<<"Enter the data (press -1 to stop taking data)...."<<endl;
    int data;
    cin>>data;
    while(data!=-1)
    {
        root = insert_in_bst_recursive(root,data);
        cin>>data;
    }
}
Node* delete_from_bts(Node* root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->info == data)
    {
        // Case 1: Node has no children (leaf node)
        if (root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }
        
        // Case 2: Node has only right child
        if (root->right != NULL && root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Node has only left child
        if (root->right == NULL && root->left != NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 4: Node has two children
        if (root->left != NULL && root->right != NULL)
        {
            int min = minval(root->right);
            root->info = min;
            root->right = delete_from_bts(root->right, min);
            return root;
        }
    }
    else if (root->info > data)
    {
        root->left = delete_from_bts(root->left, data);
        return root;
    }
    else
    {
        root->right = delete_from_bts(root->right, data);
        return root;
    }
}

int minval(Node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->info;
}

int main(void)
{
    Node* root = NULL;
    take_input(root);
    display_in_order_traversing_recursive(root);
    delete_from_bts(root,0);
    return 0;
}