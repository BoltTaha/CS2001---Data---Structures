#include<iostream>
using namespace std;

class stack{

  public:
  int top;
  int length;
  int *arr;

  stack(int length)
  {
     this->length = length;
     top = -1;
     arr = new int [length];
     cout<<"Stack is successfully created "<<endl;
  }
   bool isEmpty()
   {
    if(top == -1)
    {
       return true;
    }
    return false;
   }

   void push(int n)
   {
    if(length - top > 1)
    {
      top++;
      arr[top] = n;
      
    }
    else
    cout<<"Stack is over Flow "<<endl;
    
   }

   void pop()
   {
    if(top >= 0)
    {
      top--;
    }
    else{
      cout<<"Stack is underFlow "<<endl;
    }
   }

   int peek()
   {
    if(top >= 0)
    {
      return arr[top];
    }
    else{
      cout<<"stack is empty "<<endl;
      return -1;
    }
   }
};

int main(void)
{
  stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  cout<<"The top element of the Stack is "<<s.peek()<<endl;
  s.pop();
  cout<<"The element after pop is "<<s.peek()<<endl;
  
}