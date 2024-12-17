#include<iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;
    Node(int d)
    {
      data = d;
      prev = NULL;
      next = NULL;
    }

};

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int getlength(Node* head)
{   int count = 0;
    while(head!=NULL)
    {
         count++;
         head = head->next;
    
    }
    return count;
}

void delete_node(Node* &head,int pos)
{

   if(pos<1 || pos>getlength(head)+1 )
   {
    cout<<"The Pos is Invalid "<<endl;
    return;
   }
   Node* temp = head;
   if(pos==1)
   {
       temp->next->prev = NULL;
       head = temp->next;
       temp->next = NULL;
       delete temp;
   }
   
}
int main(void)
{
    Node* node1 = new Node(3);
    node1->next = new Node(5);
    node1->next->next =  new Node (7);
    node1->next->next->next = new Node(9);

   // delete_Node(head,2);
    print(node1);
}