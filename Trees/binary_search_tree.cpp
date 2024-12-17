#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int info;
    Node(int data)
    {
        this->left = NULL;
        this->right = NULL;
        info = data;
    }

};


Node* insert_in_bst(Node* root,int data)     // recursive
{
     if(root == NULL)
     {
        Node* root = new Node(data);
        return root;
     }

     if(data < root->info)
     {
        root->left = insert_in_bst(root->left,data);
     }

     else if( data > root->info)
     {
        root->right = insert_in_bst(root->right,data);
     }
     return root;
    
}

// iterative way to insertion

// Node* insert_in_bst(Node* root,int data)
// {
//     Node* newNode = new Node(data);
//     if(root == NULL)
//     {
//         root = newNode;
//         return root;
//     }

//     Node* child = root;
//     Node* parent = NULL;

//     while(child != NULL)
//     {
//         parent = child;
//         if(data < child->info)
//         {
//             child = child->left;
//         }
//         else{
//             child = child->right;
//         }
//     }

//     if(data < parent->info)
//     {
//         parent->left= newNode;
//     }
//     else{
//         parent->right = newNode;
//     }

//     return root;

// }



void lvl_order_traversing(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
       Node* temp = q.front();
       q.pop();
       cout<<"The data in the queue is "<<temp->info<<endl;
       if(temp->left)
       {
        q.push(temp->left);
       }
       if(temp->right)
       {
        q.push(temp->right);
       }
    }
}
    

void take_input(Node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insert_in_bst(root,data);
        cin>>data;
    }
}

int main(void)
{
    Node* root = NULL;
    take_input(root);

}