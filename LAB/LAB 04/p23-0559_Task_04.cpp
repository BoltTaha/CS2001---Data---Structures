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
void sort_Linked_List(Node* &head1)
{  
   Node* compare = head1;
   Node* temp = compare->next;
   
   while(compare!=NULL)
   {
      while(temp!=NULL)
      {
        if(compare->data > temp->data)
        {
            int hold = compare->data;
           compare->data =  temp->data ;
           temp->data = hold;
           
        }
        
        temp = temp->next;
      }
      
      compare = compare->next;
      temp = compare->next;
    
      if(temp==NULL)
      {
        return;
      }
       
   }
  
}
Node* merge_list(Node* &head1,Node* &head2)
{
     Node* temp = head1;
     while(temp->next!=NULL)
     {
        temp = temp->next;
     }
     cout<<temp->data<<endl;
     temp->next = head2;
     return head1;


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

   Node* list2 = new Node(1);
   list2->next = new Node(0);
   list2->next->next = new Node(91);
   list2->next->next->next = new Node(10);
   list2->next->next->next->next = new Node(5);
   list2->next->next->next->next->next  = new Node(9);
   list2->next->next->next->next->next->next  = new Node(30);
   
   
   Node* merge = merge_list(list1,list2);
   print(merge);
    cout<<endl;
   sort_Linked_List(merge);
   print(list1);

  

    return 0;
}