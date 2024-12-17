#include <iostream>
using namespace std;

// Node structure for linked list-based queue
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Linked List-Based Queue Class
class LinkedListQueue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor
    LinkedListQueue() : front(nullptr), rear(nullptr) {}

    // Famous Operations
    // 1. Enqueue an element (add to the rear)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // 2. Dequeue an element (remove from the front)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr; // If queue is empty
        delete temp;
        return value;
    }

    // 3. Peek the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // 4. Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // 5. Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 6. Get the size of the queue
    int size() {
        int count = 0;
        Node* temp = front;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // 7. Search for an element in the queue
    bool search(int value) {
        Node* temp = front;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // 8. Reverse the queue
    void reverse() {
        if (!front || !front->next) return;

        Node* prev = nullptr;
        Node* current = front;
        Node* nextNode;

        rear = front; // Rear becomes the original front
        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        front = prev;
    }

    // 9. Get the minimum element
    int getMin() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int minVal = front->data;
        Node* temp = front;
        while (temp) {
            if (temp->data < minVal) minVal = temp->data;
            temp = temp->next;
        }
        return minVal;
    }

    // 10. Clear the queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Queue cleared!" << endl;
    }
};

// Main function
int main() {
    LinkedListQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.display();

    cout << "Minimum element: " << queue.getMin() << endl;
    cout << "Size: " << queue.size() << endl;

    return 0;
}



// array based



#include <iostream>
using namespace std;

// Array-Based Queue Class
class ArrayQueue {
private:
    int* queue;
    int front, rear, size, capacity;

public:
    // Constructor
    ArrayQueue(int cap) : capacity(cap), size(0), front(0), rear(-1) {
        queue = new int[capacity];
    }

    // Destructor
    ~ArrayQueue() {
        delete[] queue;
    }

    // Famous Operations
    // 1. Enqueue an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
    }

    // 2. Dequeue an element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int value = queue[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    // 3. Peek the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return queue[front];
    }

    // 4. Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // 5. Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // 6. Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    // 7. Get the size of the queue
    int getSize() {
        return size;
    }

    // 8. Search for an element in the queue
    bool search(int value) {
        for (int i = 0; i < size; i++) {
            if (queue[(front + i) % capacity] == value) return true;
        }
        return false;
    }

    // 9. Get the minimum element
    int getMin() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int minVal = queue[front];
        for (int i = 1; i < size; i++) {
            int current = queue[(front + i) % capacity];
            if (current < minVal) minVal = current;
        }
        return minVal;
    }

    // 10. Clear the queue
    void clear() {
        front = 0;
        rear = -1;
        size = 0;
        cout << "Queue cleared!" << endl;
    }
};

// Main function
int main() {
    ArrayQueue queue(10);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.display();

    cout << "Minimum element: " << queue.getMin() << endl;
    cout << "Size: " << queue.getSize() << endl;

    return 0;
}
