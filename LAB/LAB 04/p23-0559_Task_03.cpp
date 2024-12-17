#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
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

  bool remove_node(Node* &head,int data)
  {
         Node* temp = head;
         Node* previous;
         while(temp->data != data)
         {    
            previous = temp;
            temp = temp->next;
            if(temp==NULL)
         {
            return false;
         }

         }
         
         previous->next = temp->next;
         delete temp;
        
  }
int main(void)
{
   Node* list1 = new Node(7);
   list1->next = new Node(12);
   list1->next->next = new Node(152);
   list1->next->next->next = new Node(1288);
   list1->next->next->next->next = new Node(110);
   list1->next->next->next->next->next  = new Node(307);
   list1->next->next->next->next->next->next  = new Node(3);

   Node* head = list1;
   print(head);
   if(remove_node(head,110)){         //want to delete 110 from the linked list
    cout<<"Element is Successfully Deleted "<<endl;

   }
   else{
    cout<<"Element is not foun in the List "<<endl;
   }
   print(head);


    return 0;
}