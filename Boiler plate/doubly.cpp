#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;  // Pointer to the previous node
    Node* next;  // Pointer to the next node

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head; // Pointer to the head (first node)
    Node* tail; // Pointer to the tail (last node)

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // 1. Insert at the head
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // 2. Insert at the tail
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // 3. Insert after a specific node
    void insertAfter(int target, int value) {
        Node* temp = head;
        while (temp && temp->data != target) {
            temp = temp->next;
        }
        if (temp) {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next) {
                temp->next->prev = newNode;
            } else {
                tail = newNode; // If new node is the last node
            }
            temp->next = newNode;
        } else {
            cout << "Node with value " << target << " not found!" << endl;
        }
    }

    // 4. Delete a node by value
    void deleteNode(int value) {
        if (!head) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr; // List becomes empty
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp && temp->data != value) {
            temp = temp->next;
        }

        if (temp) {
            if (temp->next) temp->next->prev = temp->prev;
            if (temp->prev) temp->prev->next = temp->next;
            if (temp == tail) tail = temp->prev; // Update tail if last node is deleted
            delete temp;
        }
    }

    // 5. Reverse the doubly linked list
    void reverse() {
        Node* current = head;
        Node* temp = nullptr;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    }

    // 6. Find the middle node
    void findMiddle() {
        if (!head) return;

        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle node is: " << slow->data << endl;
    }

    // 7. Detect cycle (not common but possible in a doubly linked list)
    bool detectCycle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    // 8. Remove duplicates in a sorted doubly linked list
    void removeDuplicates() {
        Node* current = head;
        while (current && current->next) {
            if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = temp->next;
                if (temp->next) temp->next->prev = current;
                else tail = current; // Update tail if last node is removed
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    // 9. Merge two sorted doubly linked lists
    static DoublyLinkedList mergeSortedLists(DoublyLinkedList& l1, DoublyLinkedList& l2) {
        Node* p1 = l1.head;
        Node* p2 = l2.head;
        DoublyLinkedList result;

        while (p1 && p2) {
            if (p1->data < p2->data) {
                result.insertAtTail(p1->data);
                p1 = p1->next;
            } else {
                result.insertAtTail(p2->data);
                p2 = p2->next;
            }
        }

        while (p1) {
            result.insertAtTail(p1->data);
            p1 = p1->next;
        }
        while (p2) {
            result.insertAtTail(p2->data);
            p2 = p2->next;
        }

        return result;
    }

    // 10. Find the length of the doubly linked list
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to demonstrate the operations
int main() {
    DoublyLinkedList list;

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

    // Find middle
    list.findMiddle();

    // Length
    cout << "Length: " << list.length() << endl;

    // Duplicate removal (Example assumes sorted list)
    list.insertAtTail(30);
    list.insertAtTail(30);
    list.removeDuplicates();
    list.display();

    // Detect cycle (No cycle in this example)
    cout << "Cycle detected: " << (list.detectCycle() ? "Yes" : "No") << endl;

    // Merge two lists
    DoublyLinkedList list2;
    list2.insertAtHead(5);
    list2.insertAtTail(15);
    DoublyLinkedList mergedList = DoublyLinkedList::mergeSortedLists(list, list2);
    mergedList.display();

    return 0;
}
