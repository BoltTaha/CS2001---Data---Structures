#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the end of the linked list
void insert(Node** head, int data) {
    Node* newNode = new Node(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to perform Bubble Sort on a linked list
void bubbleSort(Node* head) {
    if (!head) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Example usage
int main() {
    Node* head = nullptr;

    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 3);

    cout << "Original List: ";
    printList(head);

    bubbleSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
