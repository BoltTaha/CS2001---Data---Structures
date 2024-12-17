#include<iostream>
using namespace std;

class Node {

public:
    char data;
    Node* next;
    Node(char d) {
        data = d;
        next = NULL;
    }
};
bool check_palindrom(Node* node)
{
      Node* slow = node;
      Node* fast = node;

      while(fast != node && fast->next !=node)
      {
          slow = slow->next;
          fast = fast->next->next;
      }
      Node* mid = slow;
      Node* previous = NULL;
      Node* next = NULL;

      while(slow!= node)
      {
            next = slow->next;
            slow->next = previous;
            previous = slow;
            slow = next;
            
      }
      slow = previous;
      fast = node;
      while(fast < slow)
      {
        if(fast->data != slow->data)
        {
            return false;
        }
          fast = fast->next;
          slow = slow->next;
      }
      return true;    
}
int main(void)
{
   Node* node = new Node('A');
   node->next = new Node('B');
   node->next->next = new Node('C');
   node->next->next->next = new Node('C');
   node->next->next->next->next = new Node('B');
   node->next->next->next->next->next = new Node('A');
   node->next->next->next->next->next->next = node;
   
    if(check_palindrom(node))
    {
        cout<<"Palindrom "<<endl;
    }
    else{
        cout<<"Not a Palindrom"<<endl;
    }
   









    return 0;
}