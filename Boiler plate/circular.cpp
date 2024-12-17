#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* tail; // Pointer to the tail node for easier insertion and traversal

public:
    // Constructor
    CircularLinkedList() : tail(nullptr) {}

    // 1. Insert at the head
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    // 2. Insert at the tail
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 3. Delete a node by value
    void deleteNode(int value) {
        if (!tail) return;

        Node* current = tail->next;
        Node* previous = tail;

        do {
            if (current->data == value) {
                if (current == tail && current->next == tail) {
                    // Single node in the list
                    tail = nullptr;
                } else {
                    previous->next = current->next;
                    if (current == tail) {
                        tail = previous; // Update tail if deleting the tail node
                    }
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != tail->next);

        cout << "Value " << value << " not found in the list!" << endl;
    }

    // 4. Traverse and display the list
    void display() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(circular)" << endl;
    }

    // 5. Reverse the circular linked list
    void reverse() {
        if (!tail || tail->next == tail) return;

        Node *prev = nullptr, *current = tail->next, *next = nullptr;
        Node* head = tail->next;

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        head->next = prev;
        tail = head;
    }

    // 6. Find the length of the list
    int length() {
        if (!tail) return 0;

        int count = 0;
        Node* temp = tail->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != tail->next);

        return count;
    }

    // 7. Search for a value in the list
    bool search(int value) {
        if (!tail) return false;

        Node* temp = tail->next;
        do {
            if (temp->data == value) return true;
            temp = temp->next;
        } while (temp != tail->next);

        return false;
    }

    // 8. Split the circular linked list into two halves
    pair<CircularLinkedList, CircularLinkedList> split() {
        CircularLinkedList list1, list2;

        if (!tail || tail->next == tail) {
            // Single node or empty list
            if (tail) list1.insertAtTail(tail->data);
            return {list1, list2};
        }

        Node* slow = tail->next;
        Node* fast = tail->next;

        // Find middle using slow and fast pointers
        while (fast->next != tail->next && fast->next->next != tail->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Create first half
        Node* firstHalf = tail->next;
        list1.tail = slow;
        list1.tail->next = firstHalf;

        // Create second half
        Node* secondHalf = slow->next;
        slow->next = tail->next; // Close first half
        list2.tail = tail;
        list2.tail->next = secondHalf;

        return {list1, list2};
    }

    // 9. Detect cycle (always present in a circular linked list)
    bool detectCycle() {
        return tail != nullptr;
    }

    // 10. Insert after a specific node
    void insertAfter(int target, int value) {
        if (!tail) return;

        Node* temp = tail->next;
        do {
            if (temp->data == target) {
                Node* newNode = new Node(value);
                newNode->next = temp->next;
                temp->next = newNode;

                if (temp == tail) {
                    tail = newNode; // Update tail if added after the last node
                }
                return;
            }
            temp = temp->next;
        } while (temp != tail->next);

        cout << "Node with value " << target << " not found!" << endl;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (!tail) return;

        Node* temp = tail->next;
        Node* nextNode;

        do {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != tail->next);

        tail = nullptr;
    }
};

// Main function to demonstrate the operations
int main() {
    CircularLinkedList list;

    // Insertion
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAfter(20, 25);
    list.display();

    // Deletion
    list.deleteNode(25);
    list.display();

    // Reverse
    list.reverse();
    list.display();

    // Length
    cout << "Length: " << list.length() << endl;

    // Search
    cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << endl;

    // Detect cycle
    cout << "Cycle detected: " << (list.detectCycle() ? "Yes" : "No") << endl;

    // Split the list
    auto [list1, list2] = list.split();
    cout << "First Half: ";
    list1.display();
    cout << "Second Half: ";
    list2.display();

    return 0;
}
