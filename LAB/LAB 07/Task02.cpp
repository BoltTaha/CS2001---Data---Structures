#include<iostream>
#include <climits>

using namespace std;

class Node
{
    public:
    int info;
    Node* next;
    Node(int data)
    {
        this->info = data;
        next = NULL;
    }

};
class Stack{
    public:
    int min;
    Node*top;
    
    Stack()
    {
        min = INT_MAX;
        top = NULL;
        //cout<<min;
    }
     
    void push(int data)
    {
       Node* newNode = new Node(data);
       if(top==NULL)
       {
           top = newNode;
           if(min>top->info)
           {
            min = top->info;
           }
          cout<<top->info<<" ";
           return;
       }
          newNode->next = top;
          top = newNode;
          if(min>top->info)
           {
            min = top->info;
           }
            cout<<top->info<<" ";
            //cout<<min;
        
           
    }
    
    void print()
    {
        Node* temp = top;
        while(temp!=NULL)
        {
            cout<<temp->info<<endl;
            temp = temp->next;
        }
       // cout<<"Min is "<<min;
    }
void pop()
{
    // Check if the stack is empty
    if (top == NULL) {
        cout << "Stack is empty!" << endl;
        return;
    }


    Node* temp = top;
    top = top->next;
    if (temp->info == min) {
        if (top == NULL) {
            min = INT_MAX;   // stack is empty
        } else {
           
            Node* current = top;
            min = current->info;  // Initialize with the new top element's value
            while (current != NULL) {
                if (current->info < min) {
                    min = current->info;
                }
                current = current->next;
            }
        }
    }
     
    delete temp;
}


};
int main(void)
{
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(67);
    s.push(1);
    s.push(90);
    cout<<endl;
   
   while(s.top!=NULL)
   {
    s.pop();
    if(s.min==INT_MAX)
    {
        break;
    }
    cout<<s.min<<" ";
   }

    
    // s.print();





    return 0;

}