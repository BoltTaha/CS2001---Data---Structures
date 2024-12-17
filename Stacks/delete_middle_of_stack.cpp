#include<iostream>
#include<stack>

using namespace std;

void delete_from_middle(stack<int> s,int count,int n);
{
     if(  !s.empty() && count == n / 2)
     {
      s.pop();
      return;
     }

     int hold = s.top();
     s.pop();

     delete_from_middle(s,coun+1,n);

     st.push(hold);



}
