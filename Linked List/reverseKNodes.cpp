#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void reverseKNodes(Node*& head, int k) {
    if (!head || k <= 1) return; // No need to reverse if head is null or k is less than 2

    Node* curr = head;
    Node* prevTail = nullptr; // To connect the end of the previous block

    while (curr) {
        Node* blockHead = curr; // Start of the current block
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;

        // Reverse k nodes
        while (curr && count < k) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the link
            prev = curr;       // Move prev to this node
            curr = next;       // Move to the next node
            count++;
        }

        // Connect the reversed block to the next segment
        if (!prevTail) {
            head = prev; // Update head if this is the first block
        } else {
            prevTail->next = prev; // Link the last block's end to the new head
        }

        // Connect the end of the reversed block to the next segment (skipping the next k nodes)
        blockHead->next = curr;

        // Skip the next k nodes
        count = 0;
        while (curr && count < k) {
            prevTail = curr; // Move prevTail to the end of the skipped nodes
            curr = curr->next; // Move to the next node
            count++;
        }
    }
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);

    reverseKNodes(head, 3);

    print(head); // Expected output: 3 2 1 4 5 6 9 8 7

    return 0;
}
