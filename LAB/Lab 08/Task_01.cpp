#include<iostream>
using namespace std;

class Node
{
     public:

     int info;
     Node* next;

     Node(int n)
     {
        info = n;
        next = NULL;
     }

};

class Queue{
     public:
     Node* front;
     Node* rear;
   
     Queue()
     {   
     
        front = NULL;
        rear = NULL;
     }

     bool isEmpty()
     {
        if(front == NULL)
        {
            return true;
        }
        return false;
     }

     void Enqueue(int n){
        Node* newNode = new Node(n);
       if(isEmpty())
       {
           front = rear = newNode;
           return;
       }
       rear->next = newNode;
       rear = newNode;
     }


     int dequeue()
     {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        Node* temp = front;
        int ele  = temp->info;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return ele;
     }

    void ClearQueue() 
    {
        while (!isEmpty()) 
        {
           cout<< dequeue() <<" ";
        }
    }
    

}; 

int main(void)
{    
    Queue obj;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int test_cases;
    cin>>test_cases;
     
    while(test_cases--)
    {
           int size, k;
        cin >> size >> k;
        while(size--)
        {   int ele;
            cin>>ele;
            obj.Enqueue(ele);
        }
        int ele;
        while(k--)
        {
             ele = obj.dequeue();
            obj.Enqueue(ele);

        }
        // cout << "Dequeued elements for this test case: ";
        // // while (!obj.isEmpty()) {
        // //     cout << obj.dequeue() << " ";
        // // }
        // cout << endl;

    obj.ClearQueue();
    cout<<endl;

    }
    


    return 0;
}