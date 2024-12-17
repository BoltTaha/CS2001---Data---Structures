#include<iostream>
#include<stack>
#include<queue>

using namespace std;

// bool check_palindrom(queue<char> q)
// {
//     stack<char> s;
//     queue<char> q2;
//     q2 = q;
//     while(!q2.empty())
//     {
//         char hold = q2.front();
//         s.push(hold);
//         q2.pop();
//     }

//     while (!q.empty() && !s.empty())
//     {
//         char hold1 = q.front();
//         char hold2 = s.top();
//         if(hold1 != hold2)
//         {
//             return false;
//         }
//         q.pop();
//         s.pop();
//     }
//     return true;
    
// }
bool check_palindrom(queue<char> q)
{   int count = 1;
    if(count == q.size()/2 + q.size() % 2)
    {
      return true;
    }
    char hold = q.front();
    q.pop();
    count++;
    rev_half_palindrom(q);
    if(hold!=q.front())
    {
        return false;
    }
    return true;
}


int main(void)
{
    queue<char> q;
    q.push('c');
    q.push('i');
    q.push('v');
     q.push('i');
    q.push('c');
   // q.push('');
    if(check_palindrom(q))
    {
        cout<<"Palindrom "<<endl;

    }
    else{
        cout<<"Not a Palindrom "<<endl;
    }
    return 0;
}