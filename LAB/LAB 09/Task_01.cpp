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

Node* insert_in_bst_itearative(Node* root,int val)   
{
    Node* new_Node = new Node (val);

    if(root == NULL)
    {
        return new_Node;
    }
    Node* parent;
    Node* child = root;
    while(child != NULL)
    {
        parent = child;
        if(child->info > val)
        {
            child = child->left;
        }
        else if(child->info < val)
        {
            child = child->right;
        }
    }

    if(parent->info > val)
    {
        parent->left = new_Node;
    }
    else if(parent->info < val)
    {
        parent->right = new_Node;
    }
    return root;
}


void take_input(Node* &root)
{
    cout<<"Enter the data (press -1 to stop taking data)...."<<endl;
    int data;
    cin>>data;
    while(data!=-1)
    {
        root = insert_in_bst_itearative(root,data);
        cin>>data;
    }
}

void display_in_order_traversing_recursive(Node* root)     //recursive
{
    if(root == NULL) return;

     display_in_order_traversing_recursive(root->left);
    cout<<root->info<<" ";
     display_in_order_traversing_recursive(root->right);
}

void display_in_order_traversing_iterative(Node* root)     //
{
   if(root == NULL) return;
   stack<Node*> s;

   while(root != NULL || !s.empty())
   {
    if(root != NULL)
    {
        s.push(root);
        root = root->left;
    }
    else 
    {
         root = s.top();
        cout<<root->info<<" ";
        s.pop();
        root = root->right;
    }
    
   }
}


int main(void)
{
    Node* root = NULL;
    take_input(root);
    display_in_order_traversing_iterative(root);

    return 0;
}