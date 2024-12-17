#include<iostream>

using namespace std;


class Node{
    public:
    int data;
    Node* next;
   

    Node(int data)
    {
        this->data = data;
        next = NULL;
        
    }
};

void insert_at_tail(Node* &head , int info)
{ 
     Node* newNode = new Node(info);
    if(head==NULL)
    {
      head = newNode;
      head->next = head;
     
      return;
    }
    
     Node* temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
     temp->next = newNode; 
     newNode->next = head;


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

void deleteOdd(Node* &head){
       if(head==NULL)
    {
        return;
    }
       
       Node* curr = head;
       Node* temp = NULL;
       Node* track = head->next;
       int pos = 1;
       
       while(track->next!= head)
       {
       if(pos == 1)
       {
          temp = curr;
          curr = curr->next;
          
          while (temp->next != head)
          {
            temp = temp->next;
          }
          temp->next = curr;
          temp = head;
         
          head = head->next;
          
          delete temp;
          temp = NULL;
          
         
       }
         
        else if(pos % 2 != 0)
       {
         
        temp = curr->next;
        curr->next = temp->next;
        delete temp;

        temp = NULL;
       // head = curr;
        
       }
       else{
        //curr = curr->next;
       }
       track = track->next;
       pos++;
       }

       
      
}


int main(void)
{
     Node* node = NULL;

    insert_at_tail(node,1);
    insert_at_tail(node,2);
    insert_at_tail(node,3);
    insert_at_tail(node,4);
    insert_at_tail(node,5);
    insert_at_tail(node,6);
    print(node);
    deleteOdd(node);
    print(node);

    return 0;
}