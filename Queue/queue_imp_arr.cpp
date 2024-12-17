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
    void Enqueue(int n)
    {
        if(Full())
        {
            cout<<"Queue is Overflow "<<endl;
        }
        else{
            arr[rear] = n;
            rear++;
        }
    }

    int Dequeue()
    {   int n = -1;
        if(Empty())
        {
            cout<<"Queue is empty "<<endl;
        }
        else{
           n = arr[front];
            front++;
        }
        return n;

    }

    int peek()
    {  
       if(Empty())
       {
        cout<<"Queue is empty "<<endl;
        return -1;
       }
       return arr[front];
    }

    bool Empty()
    {
       if(front == rear)
       {
        return true;
       }
       return false;
    }

    bool Full()
    {
        if(rear == size-1)
        {
            return true;

        }
        return false;
    }
};

Queue::Queue(int size)
{
      arr = new int [size];
      front = 0;
      rear = 0;
}

Queue::~Queue()
{
}

int main(void)
{
   
   Queue q(5);

   q.Enqueue(1);
   q.Enqueue(3);
   cout<<"The peek element of the Queue is "<<q.peek()<<endl;
   q.Dequeue();
    cout<<"The peek element of the Queue is "<<q.peek()<<endl;





    return 0;
}