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

class LinkedList{
      
      public:
      Node* head;
      Node* tail;
      LinkedList() : head(NULL),tail(NULL)
      {

      }
      void insert_at_head(int n)
      {
        Node* temp = new Node(n);
       

        if(head==NULL)
        {    head = temp;
             tail = temp;
            return;
        }
        
       temp->next = head;
      // tail = tail->next; 
       head = temp;
       
      }

     void insert_at_tail(int data)
     {   
        
        if(tail==NULL)
     { 
        insert_at_head(data);
        return;
      
     }
          Node* newNode = new Node(data);
          tail->next = newNode;
          tail = tail->next;    
     } 
      void print()
      {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
      }
};

int main(void)
{
    LinkedList obj;
    obj.insert_at_tail(155);
    obj.insert_at_head(5);
    obj.print();
    obj.insert_at_head(9);
    obj.print();
    obj.insert_at_tail(97);
    obj.print();

}