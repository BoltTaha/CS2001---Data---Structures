#include<iostream>

using namespace std;

class node{
    
    public:

    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }

};

void insertAtStart(node* &head, int data)
{

     node* temp = new node(data);
    temp->next = head;
    head = temp; 
}

void insertAtend(node* &tail,int data)
{
    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
}
void print(node* &head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<< temp -> data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(void)
{
      node* node1 = new node(12);
    
    node* head = node1;
    node* tail = node1;
    print(tail);
    insertAtend(tail,9);
    print(tail);


 
}