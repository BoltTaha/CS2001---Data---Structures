#include<iostream>
using namespace std;

class Node{
   public:
   Node* previous;
   int info;
   Node* next;

   Node(int d)
   {
    info = d;
    previous = NULL;
    next = NULL;
   }



};
void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
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
void insert_at_head(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head->previous = temp;
    head = temp;

}

void insert_at_tail(Node* &head,int d)
{
   Node* temp = new Node(d);
   if(head==NULL)
   {
    head = temp;
    return;
   }
   Node* tail = head;
   while(tail->next!=NULL)
   {
      tail = tail->next;
   }
   tail->next = temp;
   temp->previous = tail;


}
void insert_at_pos(Node* &head,int d, int pos)
{
    if(pos>getlength(head)+1)
    {
        cout<<"The pos is greter then the length "<<endl;
        return;
    }
    if(pos==1)
    {
        insert_at_head(head,d);
        return;
    }
    if(pos==getlength(head)+1)
    {
       insert_at_tail(head,d);
       return;
    }
    int count = 1;
    Node* nodetoinsert  = new Node(d);
    Node* current = head;

    while(count < pos-1)
    {
      current = current->next;
      count++;
    }
     nodetoinsert->next = current ->next;
     current->next->previous = nodetoinsert;
     current->next = nodetoinsert;
     nodetoinsert->previous = current;
}

int main(void)
{
    Node* node1 = new Node(10);
    // node1->next = new Node(1);
    // node1->next->next = new Node(4);
    // node1->next->next->next = new Node(18);
   Node* head = node1;
    print(head);
   

    insert_at_head(head,18);
    print(head);
     //cout<<getlength(head)<<endl;
     insert_at_tail(head,9);
     print(head);

}