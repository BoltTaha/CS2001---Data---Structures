#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
    //creation of stack
   stack<int> s;

   //push operation aka insert at top;
   s.push(1);
   s.push(2);
   s.push(3);

   cout<<"Print the top element "<< s.top()<<endl;
   s.pop(); // delete the top element

   cout<<"Print the top element "<<s.top() <<endl;

   if(s.empty())
   {
    cout<<"The stack is empty"<<endl;
   }
   else{
    cout<<"The stack is not empty "<<endl;
   }

   cout<<"Size of stack is "<<s.size()<<endl;




 



    return 0;
}

