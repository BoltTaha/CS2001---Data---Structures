#include<iostream>
using namespace std;

class Queue
{

public:
   int size;
   int *arr;
   int front;
   int rear;
    Queue(int);
    ~Queue();
    bool is_empty();
   bool enqueue(int n)
   {
      if(( front == 0 && rear == size-1 ) || (rear == front - 1))
      {
        return false;
      }
      else if(front == -1)
      {
        front = rear = 0;
      }
      else if( rear = size - 1 && front != 0)
      {
        rear = 0;
      }
      else{
        rear++;
      }
      arr[rear] = n;
      return true;
   }
   int Dequeue();
};

Queue::Queue(int n)
{
    arr = new int[size];
}

Queue::~Queue()
{
}
