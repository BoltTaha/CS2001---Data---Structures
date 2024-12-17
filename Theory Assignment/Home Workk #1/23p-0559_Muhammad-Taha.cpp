#include<iostream>

using namespace std;

class Nodeee {          //Node class to for int 
public:
    int data;
    Nodeee* next;

    Nodeee(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stackkkk {              //stack class for (int) for evaluation the postfix expression
private:
    Nodeee* top;

public:
    Stackkkk() {
        top = nullptr;
    }

    void push(int data) {
        Nodeee* newNode = new Nodeee(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        Nodeee* temp = top;
        int poppedData = top->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};


    class Node        //Node class for the char
   {

      public:
      char info;
      Node* next;
      Node(char d)
      {
      this->info = d;
      next = NULL;
      }
    };

class Stack{                       //stack class for 
public:
    Node* top;
    Stack()
    {
    top = NULL;
    }
    void push(char c)
    {
    Node* new_Node = new Node(c);
    new_Node->next = top;
    top = new_Node;
    //cout<<c<<" pushed to Stack "<<endl;
    }


char peek()
{
  if(top != NULL)
  {
  return top->info;
  }
  return '\0';
  }

char pop()
{
    if(top != NULL)
    {
    Node* temp = top;
    top = top->next;
    char hold = temp->info;
    delete temp;
    return hold;

}
    return '\0';

}

bool isEmpty() {
return top == NULL;
}

};

class infix_to_postfix
{
public:
string result;
infix_to_postfix()
{  result = "";}

int prec(char data)
{
if(data == '^')
{
    return 3;
}
else if(data == '*' || data == '/')
{
return 2;
}

else if( data == '+' || data == '-')
{
return 1;
}
else{
return -1;
}
}

string conversion(string infix)
{  
Stack s;
for(int i = 0; i < infix.length(); i++)
{
char c = infix[i];


if( (c >= 'A' && c<= 'Z') || (c >= 'a' && c<= 'z') || (c >= '0' && c<= '9'))
{
    result = result + c;
    while (i + 1 < infix.length() && (infix[i + 1] >= '0' && infix[i + 1] <= '9'))  //while loop for dual digit
     {

        result += infix[++i]; //for dual digit integer
    }
     result = result + " ";
}

else if( c == '(')
{
    s.push(c);
}

else if(c == ')')        // if closed bracket is come we pop out until the open bracket is come
{
    while(s.peek() != '(')
    { 
        result = result + s.pop();
        result += " ";
    }
    s.pop(); // Remove '(' from the stack
}

else if( c == '^' || c == '*' || c == '/'  || c == '+'  || c == '-')
{ 

if(s.isEmpty())
{ 
  s.push(c);
}
else
{
  char hold_stack = s.peek();

  if(hold_stack == '(')    
  {
  s.push(c);
  }
  
else
{
  int precedence_of_stack_elment = prec(hold_stack);
  int precedence_of_char = prec(c);

  while (precedence_of_stack_elment >= precedence_of_char )     //if the precedence of stack is greater than the precedence of the char 
  {
    if(precedence_of_stack_elment >= precedence_of_char)
    {
    result = result +  s.pop();     //pop until the precdence of stack is less is tah the precedence of char
    result += " ";
    }
      if(s.isEmpty())
      {
       break;
      } 
    hold_stack = s.peek();
    if(hold_stack == '(')
    {
      break;
    }
    int precedence_of_stack_elment = prec(hold_stack);
          
  }
  s.push(c);

}
}

}


}
while(!s.isEmpty())
{
result = result + s.pop();
result += " ";
}
return result;
}
    int manualStringToInt(string str)     //This function is use to convert string to decimal 
    {
    int result = 0;
    for (int i = 0; i < str.length(); i++) 
    {
        char c = str[i]; 
        result = result * 10 + (c - '0'); // Convert char to int and add to result
    }
    return result;
}


 int evaluate(string s) {
    Stackkkk st;

    for (int i = 0; i < s.length(); i++) 
    {
        char c = s[i];

        if(c == ' ') \
        {
            continue;
        }

        if(isdigit(c))       //check if the number is digit 
        {
            string num;

            while (i < s.length() && isdigit(s[i]))
           {
                num += s[i];     //merge the character if they are combined
                i++;      
            }
            i--;

            st.push(manualStringToInt(num)); // Use manual conversion
        } 
        else if(c == '+' || c == '-' || c == '*' || c == '/') 
        {
            int operand2 = st.pop();
            int operand1 = st.pop();

            switch (c)
             {
                case '+':
                    st.push(operand1+operand2);
                    break;
                case '-':
                    st.push(operand1-operand2);
                    break;
                case '*':
                    st.push(operand1*operand2);
                    break;
                case '/':
                    if (operand2 != 0) 
                    {
                        st.push(operand1/operand2);
                    } else 
                    {
                        cout<<"Error: Division by zero!"<<endl;
                        return 0;
                    }
                    break;
            }
        }
    }

    return st.pop();
}
};
int main(void)
{

string infix = "";
string postfix;
  cout<<"Enter the expression in the from of INfix Notation: "<<endl;
  getline(cin,infix);

infix_to_postfix obj;
int result = 0;

postfix = obj.conversion(infix);

result = obj.evaluate(postfix);

cout<<"The Expression in the Postfix Notation is "<<endl;
cout<<postfix<<endl;

cout<<"The Result after Evaluation is "<<result;




return 0;
}