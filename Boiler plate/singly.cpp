#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // 1. Insert at the head
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insert at the tail
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
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
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    // 5. Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
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

    // 7. Detect a cycle in the linked list
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

    // 8. Remove duplicates from a sorted linked list
    void removeDuplicates() {
        Node* current = head;
        while (current && current->next) {
            if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    // 9. Merge two sorted linked lists
    static SinglyLinkedList mergeSortedLists(SinglyLinkedList& l1, SinglyLinkedList& l2) {
        Node* dummy = new Node(0);
        Node* current = dummy;

        Node* p1 = l1.head;
        Node* p2 = l2.head;

        while (p1 && p2) {
            if (p1->data < p2->data) {
                current->next = p1;
                p1 = p1->next;
            } else {
                current->next = p2;
                p2 = p2->next;
            }
            current = current->next;
        }
        current->next = (p1) ? p1 : p2;

        SinglyLinkedList result;
        result.head = dummy->next;
        delete dummy;
        return result;
    }

    // 10. Find the length of the linked list
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~SinglyLinkedList() {
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
    SinglyLinkedList list;

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
    SinglyLinkedList list2;
    list2.insertAtHead(5);
    list2.insertAtTail(15);
    SinglyLinkedList mergedList = SinglyLinkedList::mergeSortedLists(list, list2);
    mergedList.display();

    return 0;
}
