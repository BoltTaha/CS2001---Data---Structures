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
      int size = 0;
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
       size++;
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
          size++; 
     } 

    bool insert_at_position(int pos,int data)
     {
           if(pos<1 || pos>size)
           {
            return false;
           }
           if(pos==1)
           {
            insert_at_head(data);
            return true;
           }
           if(pos==size)
           {
            insert_at_tail(data);
            return true;
           }
           Node* newNode = new Node(data);
           Node* temp = head;
           int count = 1;
           while(count != pos - 1)
           {
             temp = temp->next;
             count++;
           }
           
       newNode->next = temp->next;
       temp->next = newNode;
      size++;
      return true;
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
    obj.insert_at_tail(17);
    obj.insert_at_tail(67);
    obj.insert_at_tail(7);
    obj.print();
    if(obj.insert_at_position(5,8))
    {
        cout<<"Element is succesfullt added at the specific position"<<endl;
    }
    else{
        cout<<"Element is not added successfullt"<<endl;
    }
    obj.print();

     if(obj.insert_at_position(2,101))
    {
        cout<<"Element is succesfullt added at the specific position"<<endl;
    }
    else{
        cout<<"Element is not added successfullt"<<endl;
    }
    obj.print();

}