#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    
    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack" << endl;
    }
    
    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
            cout << "Popped from stack" << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }
    
    char peek() {
        return top ? top->data : '\0'; // Return '\0' if stack is empty
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
};

   int bin(string str)
   {
       Stack s;
      int result = 0;
       for(int i = 0; i < str.length(); i++)
       {
        char c = str[i];
        s.push(c);
       }
       int  i = 0;
       while(!s.isEmpty())
       {
           int hold = s.peek();
           s.pop();
           if(hold == '1')
           {
            if(i == 0)
            {
                result = result + 1;
            }
            else{
                result = result + (2 * i);
                 if(i>=2)
                 {
                    i++;
                 }
                
            }
           }
           i++;
       }
           return result;
   }
int main(void)
{
    string str = "1101";
    int l = bin(str);

    cout<<l;


}