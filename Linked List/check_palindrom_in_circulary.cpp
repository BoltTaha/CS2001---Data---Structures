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
void check_palindrom(Node* node)
{
      Node* slow = node;
      Node* fast = node;

      while(fast != NULL &&fast->next !=NULL)
      {
          slow = slow->next;
          fast = fast->next->next;
      }
    //   Node* mid = slow;
    //   while(slow->next != NULL)
    //   {

    //   }
    cout<<slow->data;
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
   
    check_palindrom(node);
    // if()
    // {
    //     cout<<"Palindrom "<<endl;
    // }
    // else{
    //     cout<<"Not a Palindrom"<<endl;
    // }
   









    return 0;
}