#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* previous;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        previous = NULL;
    }
};
void insert_at_head(Node* &head,int info)
{
    Node* newNode = new Node(info);
    if(head==NULL)
    {
      head = newNode;
      head->next = head;
      head->previous = head;
      return;
    }
  //  Node* temp = head;
    newNode->next = head;
    newNode->previous = head->previous;
    head->previous->next = newNode;
    head->previous = newNode;
    head = newNode;
    

}

void insert_at_tail(Node* &head , int info)
{ 
     Node* newNode = new Node(info);
    if(head==NULL)
    {
      head = newNode;
      head->next = head;
      head->previous = head;
      return;
    }
    Node* tail = head->previous;
    newNode->previous = tail;
    newNode->next = tail->next;
    tail->next = newNode;
    head->previous = newNode;

}
void print(Node* head)
{   Node* temp = head;
    do
    {
         cout<<temp->data<<" ";
        temp = temp->next;
    } 
    
    while(temp != head);
    
    cout<<endl;
}

void reverse_circular(Node* &head)
{
    if(head==NULL)
    {
        return;
    }
    Node* curr = head;
    Node* temp = NULL;
    do{
        temp = curr->next;
        curr->next = curr->previous;
        curr->previous = temp;
        curr = temp;
        
    }
     while (curr != head);
     
      head = curr->next;
}
int main(void)
{
    Node* node =NULL;
    // insert_at_head(node,8);
    //  insert_at_head(node,9);
    //print(node);
    insert_at_tail(node,1);
    insert_at_tail(node,2);
    insert_at_tail(node,3);
    insert_at_tail(node,4);
    insert_at_tail(node,5);
    insert_at_tail(node,6);
    insert_at_tail(node,7);
    print(node);
    reverse_circular(node);
    print(node);


    return 0;
}