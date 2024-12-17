#include<iostream>

using namespace std;

class node
{
     public:
     int info;
     node* next;

     node(int data)
     {
        info = data;
        next = NULL;
     }



};
int main(void)
{
      node *ptr = new node(10);

      cout<<"The Data in the Node is "<<ptr->info<<endl;
      cout<<"The Address of the Next Node is "<<ptr->next<<endl;  //in this case the address of next node is NULL;


    return 0;
}