#include <iostream>
#include <climits>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to calculate the maximum profit
int maxProfit(Node* head) {
    if (!head || !head->next) return -1; // Not enough data for profit
    
    int min_price = INT_MAX;
    int max_profit = -1;
    
    Node* current = head;
    while (current) {
        // Update minimum price seen so far
        if (current->data < min_price) {
            min_price = current->data;
        } else {
            // Calculate profit and update max profit
            int profit = current->data - min_price;
            max_profit = max(max_profit, profit);
        }
        current = current->next;
    }
    return max_profit;
}

// Helper function to create a linked list
Node* createLinkedList(const int arr[], int size) {
    if (size == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

// Main function
int main() {
    // Example 1
    int arr1[] = {44, 30, 24, 32, 35, 30, 40, 38, 15};
    Node* head1 = createLinkedList(arr1, 9);
    cout << maxProfit(head1) << endl; // Output: 16

    // Example 2
    int arr2[] = {10, 9, 8, 2};
    Node* head2 = createLinkedList(arr2, 4);
    cout << maxProfit(head2) << endl; // Output: -1

    // Example 3
    int arr3[] = {3, 5, 6, 8, 10, 15, 16, 25, 11};
    Node* head3 = createLinkedList(arr3, 9);
    cout << maxProfit(head3) << endl; // Output: 22

    return 0;
}
