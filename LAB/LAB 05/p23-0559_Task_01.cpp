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
bool delete_the_node(Node* &head,int ele)
{
    
    if(head==NULL)
    {
        return false;  //Linked list is empty
    }
    
    Node* temp = head;
     Node* temp1;
     if(temp->data == ele)
     {
        temp1 = temp->next;
        temp1->prev = NULL;
        temp->next = NULL;
        head = temp1;
        delete temp;

        return true;
     }
    while(temp!=NULL)
    {
        if(temp->data == ele)
        {
            break;
        }
         temp1 = temp;
        temp = temp->next;
    }
    if(temp==NULL)
    {
        return false; //no element is found in the list
    }
    // cout<<temp->data;
    // cout<<temp1->data;
    if(temp->next == NULL)
    {
        temp1->next = NULL;
        temp->prev = NULL;
        delete temp;
        return true;
    }
    
    temp1->next = temp->next;
    temp->next->prev = temp1;

    delete temp; 

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

    if(delete_the_node(head,5))
    {
        cout<<"The Element is Successfully delted"<<endl;
    }
    else
    cout<<"Element is Not found in the list "<<endl;
    print(head);

}