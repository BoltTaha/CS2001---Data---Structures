#include<iostream>
#include<queue>
#include<stack>
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

Node* buildtree(Node* root)
{
    cout<<"ENter the Data "<<endl;
    int n;
    cin>>n;
    root = new Node(n);

    if(n == -1)
    {
        return NULL;
    }

    cout<<"Enter the Data for inserting in left 0f "<<" "<<n<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter the Data for inserting in right 0f"<<" "<<n<<endl;
    root->right = buildtree(root->right);

    return root;

}

void level_order_traversing(Node* root)
{
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
        
   while (!q.empty())
   {   
    Node* temp = q.front();
      
      q.pop();

       if(temp == NULL)
       {
        cout<<endl;
        if(!q.empty())
        {
            q.push(NULL);
        }
       }

       else
       {
     cout<<temp->info<<" ";
      if(temp->left != NULL)
      {
        q.push(temp->left);
      }

      if(temp->right != NULL)
      {
        q.push(temp->right);
      }

   }
   }
 

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

int main(void)
{
    Node* root = NULL;

    root = buildtree(root);
   level_order_traversing( root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
}

void post_order_traversal(Node* root)
{
  stack<Node*> s1,s2;
  s1.push(root);

  while(!s1.empty())
  {
     Node* newNode = s1.top();
     s1.pop();
     s2.push(newNode);

     if(newNode->left)
     {
      s1.push(newNode->left);
     }

      if(newNode->right)
     {
      s1.push(newNode->right);
     }
   

  }

  while(!s2.empty())
   {
    cout<<s2.top()<<endl;
    s2.pop();
   }
}



