#include<iostream>
using namespace std;
int postion = 1;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* find_node_by_value(Node* head,int value)
{
     if(head==NULL)
     {
         postion = 0;
         return NULL;
     }
     while(head!=NULL)
     {
        if(head->data == value)
        {
            return head;
        }
        postion++;
        head = head->next;
     }

     return NULL;
}
int main(void)
{
     Node* head = new Node(10);   // First node
Node* second = new Node(1);  // Second node
Node* third = new Node(5);   // Third node
Node* fourth = new Node(21); // Fourth node
Node* tail = new Node(56);   // Last node (tail)

// Linking the first node to the second
head->next = second;
second->prev = head;

// Linking the second node to the third
second->next = third;
third->prev = second;

// Linking the third node to the fourth
third->next = fourth;
fourth->prev = third;

// Linking the fourth node to the fifth (tail)
fourth->next = tail;
tail->prev = fourth;

 Node* temp = find_node_by_value(head,21);
 if(temp==NULL)
 {
    cout<<"Value doesn't find in the list "<<endl;
 }
 else
 {
    cout<<"The Node is find at "<<postion<<" "<<endl;
 }

}