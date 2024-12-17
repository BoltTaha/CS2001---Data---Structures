#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 1. Implement Stack using Arrays
class StackArray {
    int *arr;
    int top;
    int capacity;

public:
    StackArray(int size) {
        arr = new int[size];
        top = -1;
        capacity = size;
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// 2. Implement Stack using Linked List
struct Node {
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class StackLinkedList {
    Node *top;

public:
    StackLinkedList() : top(nullptr) {}

    void push(int x) {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (!top) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int val = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    int peek() {
        if (!top) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// 3. Reverse a Stack
void reverseStack(stack<int> &s) {
    if (s.empty()) return;
    int top = s.top();
    s.pop();
    reverseStack(s);
    s.push(top);
}

// 4. Sort a Stack
void sortedInsert(stack<int> &s, int x) {
    if (s.empty() || x > s.top()) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

void sortStack(stack<int> &s) {
    if (!s.empty()) {
        int top = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, top);
    }
}

// 5. Evaluate Postfix Expression
int evaluatePostfix(const string &expr) {
    stack<int> s;
    for (char ch : expr) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.top();
}

// 6. Convert Infix to Postfix
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string &infix) {
    stack<char> s;
    string postfix;
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// 7. Next Greater Element
vector<int> nextGreaterElement(vector<int> &nums) {
    vector<int> result(nums.size(), -1);
    stack<int> s;
    for (int i = 0; i < nums.size(); i++) {
        while (!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    return result;
}

int main() {
    // Example Usage
    cout << "--- Stack using Array ---\n";
    StackArray stackArray(5);
    stackArray.push(10);
    stackArray.push(20);
    cout << "Top element: " << stackArray.peek() << endl;
    stackArray.pop();
    cout << "Top element after pop: " << stackArray.peek() << endl;

    cout << "\n--- Stack using Linked List ---\n";
    StackLinkedList stackLL;
    stackLL.push(30);
    stackLL.push(40);
    cout << "Top element: " << stackLL.peek() << endl;
    stackLL.pop();
    cout << "Top element after pop: " << stackLL.peek() << endl;

    cout << "\n--- Reverse a Stack ---\n";
    stack<int> s;
    s.push(1); s.push(2); s.push(3);
    reverseStack(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "\n\n--- Sort a Stack ---\n";
    stack<int> s2;
    s2.push(3); s2.push(1); s2.push(4); s2.push(2);
    sortStack(s2);
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }

    cout << "\n\n--- Evaluate Postfix Expression ---\n";
    string postfix = "231*+9-";
    cout << "Result: " << evaluatePostfix(postfix) << endl;

    cout << "\n--- Infix to Postfix Conversion ---\n";
    string infix = "a+b*(c^d-e)";
    cout << "Postfix: " << infixToPostfix(infix) << endl;

    cout << "\n--- Next Greater Element ---\n";
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> nge = nextGreaterElement(nums);
    for (int n : nge) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}



bool isBalanced(string expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}




class MinStack {
    stack<int> s, minStack;

public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};





class TwoStacks {
    int *arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            cout << "Stack Underflow\n";
            return -1;
        }
    }
};




bool hasRedundantBrackets(string expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == ')') {
            bool operatorFound = false;
            while (!s.empty() && s.top() != '(') {
                char top = s.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorFound = true;
                }
                s.pop();
            }
            s.pop(); // Remove '('
            if (!operatorFound) return true;
        } else {
            s.push(ch);
        }
    }
    return false;
}
