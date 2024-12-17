#include<iostream>
using namespace std;
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
int count_no_of_nodes(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    int count = 0;
    while(head!=NULL)
    {
        head = head->next;
        count++;
    }
    return count;
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

  cout<<count_no_of_nodes(head);

}