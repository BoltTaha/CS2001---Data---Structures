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

void search(Node* root, int value) {
    if (root == NULL) {
        cout << "Value not found!" << endl;
        return;
    }

    if (root->info == value) {
        cout << "Value found! Node information: " << root->info << endl;
        return;
    }
    else if (value < root->info) {
        search(root->left, value);
    }
    else {
        search(root->right, value);
    }
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

int main(void) {
    Node* root = NULL;
    take_input(root);
    cout << "In-order traversal: ";
    in_order_traversing(root);
    cout << endl;

    int value;
    cout << "Enter a value to search in the BST: ";
    cin >> value;
    search(root, value);

    return 0;
}