#include<iostream>

using namespace std;

class Node{
  
  public:

  int info;
  Node *nextNode;

  Node(int n)
  {
    info = n;
    nextNode = NULL;
  }

};
class List{
    
    public:
   Node* head;
   int size = 0;
   List()
   {
    head = NULL;
   }
   
   void insert_at_head(int info)
{
      Node *temp = new Node(info);
      temp->nextNode = head;
      head = temp;
      size++;
}

void insert_at_tail(int info)
{
    Node* temp = new Node (info);
    if(head==NULL)
    {
        head = temp;
        return;
    }
    Node* temp1 = head;
    while(temp1->nextNode != NULL)
    {
        temp1 = temp1->nextNode;
    }
    temp1->nextNode = temp ;
    size++;
    
}
void insert_at_pos(int info,int pos)
{
      Node* temp = new Node(info);
      int count = 0;
      Node* temp2  = head;
      if(size<pos)
      {
        return;
      }
      while(count!=pos - 1)
      {
        temp2 = temp2->nextNode;
        count++;
      }


}

void print()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->info<<" ";
        temp = temp->nextNode;
    }
    cout<<endl;
}




};

int main(void)
{
    
    List linkedList;

    // Initial state of the list
    linkedList.insert_at_head(9);
    linkedList.print();  // Output: 9
    
    // Insert at head
    linkedList.insert_at_head(12);
    linkedList.print();  // Output: 12 9

    // Insert at tail
    linkedList.insert_at_tail(90);
    linkedList.print();  // Output: 12 9 90

    // Insert at position 2
    linkedList.insert_at_pos(15, 2);
    linkedList.print();  // Output: 12 15 9 90

    // Insert at position 1 (head)
    linkedList.insert_at_pos(100, 1);
    linkedList.print();  // Output: 100 12 15 9 90

    return 0;
}
