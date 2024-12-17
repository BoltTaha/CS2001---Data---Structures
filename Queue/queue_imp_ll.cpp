#include<iostream>

using namespace std;

class Node{
   
   public:
   int info;
   Node* next;
   Node(int n)
   {
           info = n;
           next = nullptr;
   }
 
};

class Queue
{
    public:
    Node* front;
    Node* rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    
    void enqueue(int n)
    {
        Node* new_node = new Node(n);
        if(Empty())
        {
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear = new_node;
    }

    int Dequeue()
    {
        if(Empty()){
            return -1;
        }
        Node* temp = front;
        front = front->next;
        int n = temp->info;
        delete temp;
        return n;
    }
    int peek()
    {
         if(Empty())
         {
            return -1;
         }
         return front->info;
    }
    bool Empty()
    {
       if(front == NULL && rear == NULL)
       {
        return true;
       }
       return false;
    }
    
};
int main(void)
{
    Queue q;
    q.enqueue(1);
    q.enqueue(78);
    q.Dequeue();
    cout<<q.peek()<<endl;
    q.Dequeue();


}