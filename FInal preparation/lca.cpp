
#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

        Node* LCA(Node *root, int n1, int n2)
        {
           if(root == NULL)
           {
               return root;
           }
           
           
            if(root->data == n1 || root->data == n2 )
            {
                return root;
            }
            
            
            Node* temp = LCA(root->left,n1,n2);
            Node* temp2 = LCA(root->right,n1,n2);
          
            if(temp != NULL && temp2 != NULL)
            {
                return root;
            }
            
           else if(temp!= NULL && temp2  == NULL)
            {
                return temp;
            }
            
           else if(temp== NULL && temp2  != NULL)
            {
                return temp2;
            }
           
           else
           {
           return NULL;
           }           
           
        }


int main() 
{
    // Hardcode the binary tree
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left =  new Node(3);
    root->left->right->right =  new Node(5);
    root->right->right = new Node(9);

   Node* hold = LCA( root,15,0);

   cout<<hold->data;



    return 0;
}