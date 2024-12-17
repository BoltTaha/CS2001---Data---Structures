#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// void sort_queue(queue<int>& p)  // Pass the queue by reference using &
// {
//     stack<int> s;
//     while(!p.empty())
//     {
//         s.push(p.front());
//         p.pop();
//     }
//     while(!s.empty())
//     {
//         p.push(s.top());
//         s.pop();
//     }

// }

queue<int> rev(queue<int> q)
    {
        // Base case: if the queue is empty, return the queue
        if(q.empty())
        {
            return q;       
        }

        // Get the front element and pop it
        int hold = q.front();
        q.pop();

        // Recur for the remaining queue
        q = rev(q);

        // Push the stored front element to the back
        q.push(hold);
        
        return q;
    }

int main(void)
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    //sort_queue(q);  // Pass the original queue by reference
    cout<<q.front();
    return 0;
}
