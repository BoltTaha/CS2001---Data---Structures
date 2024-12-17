#include<iostream>
#include<stack>
#include<queue>
 using namespace std;

 void reverse_even_odd(stack<int>& st,bool even)
 {
     stack<int> temp;
     queue<int> q1,q2;

     while(!st.empty())
     {   
       
        q1.push(st.top());
        st.pop();

     }

     while(!q1.empty())
     {
        q2.push(q1.front());
        q1.pop();
     }

     int size = q2.size();
     for(int i = 0; i < size; i++)
     {
        int hold = q2.front();
        if(hold % 2 == 0)
        {
            st.push(hold);
        }
        q2.push(hold);
     }

     if(even)
     {
        for(int j = 0; j < size ;j++)
        {
            int hold = q2.front();
            if(hold %2 == 0)
            {
                q2.push(st.top());
                st.pop();
            }
            q2.push(hold);
        }

        while(!q2.empty())
        {
            temp.push(q2.front());
            q2.pop();
           // temp.pop();
        }
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
     }
 }

int main(void)
{
    stack<int> s;
    s.push(7);
    s.push(6);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(2);
    s.push(1);
    s.push(8);

     
   
     reverse_even_odd(s,true);



    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}