#include<iostream>
#include<stack>
#include<queue>

using namespace std;

// void sot_asceding(queue<int>& q)
// {
//     int size = q.size();
//     int arr[size];
//     for(int i = 0; i<size && !q.empty(); i++)
//     {
//        arr[i] = q.front();
//        q.pop();
//     }

//    for(int i = 0; i < size - 1; i++)
// {
//     // Loop through the array and compare adjacent elements
//     for(int j = 0; j < size - i - 1; j++)
//     {
//         // Swap if the current element is greater than the next element
//         if(arr[j] > arr[j + 1])
//         {
//             int temp = arr[j];
//             arr[j] = arr[j + 1];
//             arr[j + 1] = temp;
//         }
//     }
// }
//   for(int  i = 0; i < size; i++)
//   {
//         q.push(arr[i]);
//   }

// }
void insertInSortedOrder(queue<int>& q, int element) {
    // Base case: if the queue is empty or the front element is greater than the element
    if (q.empty() || q.front() > element) {
        q.push(element);
        return;
    }

    // Remove the front element
    int temp = q.front();
    q.pop();

    // Recur to insert the element in sorted order
    insertInSortedOrder(q, element);

    // Push the removed element back into the queue
    q.push(temp);
}

// Function to sort the queue using recursion
void sortQueue(queue<int>& q) {
    // Base case: if the queue is empty, return
    if (q.empty()) {
        return;
    }

    // Remove the front element
    int element = q.front();
    q.pop();

    // Sort the remaining queue
    sortQueue(q);

    // Insert the removed element back in sorted order
    insertInSortedOrder(q, element);
}
  
int main(void)
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(10);
    q.push(1);
  // cout<<"The size of queuee is "<<q.size()<<endl;
    sortQueue(q);
    cout<<q.front()<<endl;
    q.pop();
     cout<<q.front()<<endl;
    q.pop();
     cout<<q.front()<<endl;
    q.pop();
     cout<<q.front()<<endl;
    q.pop();

    
   
    return 0;
}