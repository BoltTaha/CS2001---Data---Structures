#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor for ease of node creation
    Node(int value) : data(value), next(nullptr) {}
};
void sort_list(Node* &head)
{

    Node* temp1 = head;
    Node* temp2;
    Node* hold = head;

    while(temp1->next != NULL && hold->next != NULL)
    {
        if(temp1->data > temp1->next->data )
        {
            temp2 = temp1->next;
            hold = temp1->next;
            temp1->next = hold;
            temp2->next = temp1;
        }
        temp1 = temp1->next;
    }
    head = temp1;
}



Node* merge_list(Node* node1, Node* node2)
{
    Node* temp = node1;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node2;

    sort_list(node1);

    return node1;
}



// Function to print the linked list
void print_list(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Create first linked list: 3 -> 1 -> 4
    Node* list1 = new Node(3);
    list1->next = new Node(1);
    list1->next->next = new Node(4);

    // Create second linked list: 2 -> 5
    Node* list2 = new Node(2);
    list2->next = new Node(5);

    // Print original lists
    cout << "List 1: ";
    print_list(list1);
    cout << "List 2: ";
    print_list(list2);

    // Merge and sort the lists
    Node* merged_list = merge_list(list1, list2);

    // Print the merged sorted list
    cout << "Merged and Sorted List: ";
    print_list(merged_list);

    // Clean up memory (optional)
    Node* temp;
    while (merged_list) {
        temp = merged_list;
        merged_list = merged_list->next;
        delete temp;
    }

    return 0;
}

