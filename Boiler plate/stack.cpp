#include <iostream>
using namespace std;

// Node structure for linked list-based stack
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Linked List-Based Stack Class
class LinkedListStack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor
    LinkedListStack() : top(nullptr) {}

    // Famous Operations
    // 1. Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // 2. Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // 3. Peek the top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    // 4. Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // 5. Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 6. Get the size of the stack
    int size() {
        int count = 0;
        Node* temp = top;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // 7. Search for an element in the stack
    bool search(int value) {
        Node* temp = top;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // 8. Reverse the stack
    void reverse() {
        if (!top || !top->next) return;

        Node* prev = nullptr;
        Node* current = top;
        Node* nextNode;

        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        top = prev;
    }

    // 9. Find the minimum element
    int getMin() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int minVal = top->data;
        Node* temp = top;
        while (temp) {
            if (temp->data < minVal) minVal = temp->data;
            temp = temp->next;
        }
        return minVal;
    }

    // 10. Clear the stack
    void clear() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Stack cleared!" << endl;
    }
};

// Main function
int main() {
    LinkedListStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.display();

    cout << "Minimum element: " << stack.getMin() << endl;
    cout << "Size: " << stack.size() << endl;

    return 0;
}


// Array based


#include <iostream>
using namespace std;

// Array-Based Stack Class
class ArrayStack {
private:
    int* stack;
    int capacity;
    int top;

public:
    // Constructor
    ArrayStack(int cap) : capacity(cap), top(-1) {
        stack = new int[capacity];
    }

    // Destructor
    ~ArrayStack() {
        delete[] stack;
    }

    // Famous Operations
    // 1. Push an element onto the stack
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        stack[++top] = value;
    }

    // 2. Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return stack[top--];
    }

    // 3. Peek the top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return stack[top];
    }

    // 4. Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // 5. Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    // 6. Get the size of the stack
    int size() {
        return top + 1;
    }

    // 7. Search for an element in the stack
    bool search(int value) {
        for (int i = top; i >= 0; i--) {
            if (stack[i] == value) return true;
        }
        return false;
    }

    // 8. Reverse the stack (Temporary Array)
    void reverse() {
        if (isEmpty()) return;
        int* temp = new int[capacity];
        int idx = 0;
        for (int i = top; i >= 0; i--) {
            temp[idx++] = stack[i];
        }
        for (int i = 0; i <= top; i++) {
            stack[i] = temp[i];
        }
        delete[] temp;
    }

    // 9. Get the minimum element
    int getMin() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int minVal = stack[0];
        for (int i = 1; i <= top; i++) {
            if (stack[i] < minVal) minVal = stack[i];
        }
        return minVal;
    }

    // 10. Clear the stack
    void clear() {
        top = -1;
        cout << "Stack cleared!" << endl;
    }
};

// Main function
int main() {
    ArrayStack stack(10);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.display();

    cout << "Minimum element: " << stack.getMin() << endl;
    cout << "Size: " << stack.size() << endl;

    return 0;
}
