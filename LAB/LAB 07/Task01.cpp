#include<iostream>
using namespace std;

class Stack{

    public:
    char* String;
    string hold;
    int size;
    int top;
    Stack(int size,string temp)
    {
        this->size = size;
       String = new char[size];
       hold = temp;
       top = -1;
    }

    void push_String()
    {
         while(top!=size)
         {
            top++;
            String[top] = hold[top]; 
         }
        // cout<<String[top];
    }
    void pop_string()
    {
        int count = -1;
        while(count!=size)
        {   count++;
            hold[count] = String[top];
            top--;
        }

    }
    void print()
    {
        cout<<hold<<endl;
    }
};

int main(void)
{
    string String;
    cout<<"Enter the String that you want to Reverse "<<endl;
    getline(cin,String);

    int size = String.length() - 1;
    // cout<<String[0];
    // cout<<size;
    Stack s(size,String);
    s.push_String();
   // s.push_String();
   s.pop_string();
   s.print();






    return 0;
}