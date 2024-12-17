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

  void post_order_traversing(Node* root)
  {
    if(root == NULL)
    {
        return;
    }
    post_order_traversing(root->left);
    post_order_traversing(root->right);
    cout<<root->info<<" ";
  }

    void pre_order_traversing(Node* root)
  {
    if(root == NULL)
    {
        return;
    }
    cout<<root->info<<" ";
    pre_order_traversing(root->left);
    pre_order_traversing(root->right);
    
  }

     void in_order_traversing(Node* root)
  {
    if(root == NULL)
    {
        return;
    }
   
    in_order_traversing(root->left);
     cout<<root->info<<" ";
    in_order_traversing(root->right);
    
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

int main(void)
{
    Node* root = NULL;
    take_input(root);
    pre_order_traversing(root);
    post_order_traversing(root);
    in_order_traversing(root);
   
    return 0;
}