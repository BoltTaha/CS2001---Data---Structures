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



int solve(Node* root,int& i,int k)
{
    if(root == NULL)
    {
        return -1;
    }
    int left = solve(root->right,i,k);     //l
    if(left!=-1)
    {
        return left;
    }
   //n
    i++;

    if(i==k)
    {
        return root->info;
    }
//r
    return solve(root->left,i,k);
}

int kthsmallest(Node* root,int k)
{
    int i = 0;
    return solve(root,i,k);
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
 void pre_order(Node* root)
 {
    if(root == NULL) return;
    cout<<root->info<<" ";
    pre_order(root->left);
    pre_order(root->right);
 }
int main(void)
{
    Node* root = NULL;
    take_input(root);          // 8 3 9 1 0 5 3 -1
    cout<<kthsmallest(root,3);
//    pre_order(root);  
//    cout<<kthsmallest(root,3);

    return 0;
}