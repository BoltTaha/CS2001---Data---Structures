#include<iostream>
using namespace std;

class Node {

public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

// Function to insert a node at the head of the circular linked list
void insert_at_head(Node* &tail, int data) {
    Node* node = new Node(data);
    
    if (tail == NULL) {
        // If the list is empty, make the new node point to itself
        tail = node;
        tail->next = tail; 
        tail->prev = tail;
    } else {
        // Insert the new node at the head
        node->next = tail->next;  // New node points to the current head
        tail->next->prev = node;        // Tail now points to the new head
        tail->next = node;
        node->prev = tail;

    }
}
void insert_at_end(Node* &tail, int data)
{
    Node* node = new Node(data);
    if(tail == NULL) {
        // If the list is empty, the new node points to itself
        tail = node;
        node->next = node;
        node->prev = node;
    } else {
        // Insert node at the end of the list
        Node* head = tail->next;   // Get the head of the circular list

        node->next = head;         // The new node's next points to the head
        node->prev = tail;         // The new node's prev points to the tail
        head->prev = node;         // The head's prev should point to the new node
        tail->next = node;         // The current tail's next should point to the new node
        tail = node;               // Update the tail to be the new node
    }
}

void insert_at_pos(Node* &tail,int pos,int data)
{
    if(pos==1)
    {
        insert_at_head(tail,data);
    }
    else{
        Node* curr = tail ->next;
        Node* temp = new Node(data);
        int count = 1;
        while(count < pos-1)
        {
            curr= curr->next;
            count++;
        }
        temp->next = curr->next;        // New node's next points to the node after current
        temp->prev = curr;              // New node's prev points to the current node
        curr->next->prev = temp;        // The next node's prev points to the new node
        curr->next = temp;  
         
        


    }
}

// Function to print the circular linked list
void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail->next;  // Start from the head (tail->next)
    do {
        cout << temp->data << " ";  // Print data of the current node
        temp = temp->next;          // Move to the next node
    } while (temp != tail->next);   // Stop when we reach the head again
    cout << endl;
}
void insert_at_position(Node* &tail,int pos,int data)
{
    if(pos==1)
    {
        insert_at_head(tail,data);
    }
    else{
        Node* temp = tail->next;
        Node* node = new Node(data);
        int count  = 1;
        while(count < pos-1)
        {
        temp = temp->next;
        count++;
        }
        node->next = temp->next;
        temp->next = node;
    }
}

void delete_from_head(Node* &tail) {
    if (tail == NULL) {
        // If the list is empty, there is nothing to delete
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = tail->next;  // Node to be deleted (head)
    
    if (tail->next == tail) {
        // Only one node in the list
        delete temp;
        tail = NULL;
    } else {
        // More than one node in the list
        tail->next = temp->next;  // Update head to point to the next node
        delete temp;               // Free memory of the deleted node
    }
}

void delete_from_tail(Node* &tail) {
    if (tail == NULL) {
        // If the list is empty, there is nothing to delete
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail->next;  // Start from the head (tail->next)
    
    // Case when there is only one node in the list
    if (tail->next == tail) {
        delete tail;
        tail = NULL;
    } else {
        // Traverse to the node before the tail
        while (temp->next != tail) {
            temp = temp->next;
        }
        // Update the next of the second-last node to point to the head
        temp->next = tail->next;
        delete tail;  // Delete the current tail
        tail = temp;  // Update tail to the second-last node
    }
}

void delete_at_position(Node* &tail,int pos)
{
    Node* temp = tail->next;
    int count  = 1;
    while(count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node* curr = temp->next;
    temp->next = curr->next;
    delete curr;


}
int main(void) {
    Node* node = NULL;  // Initialize the tail pointer to NULL

    insert_at_head(node, 8);
    print(node);  // Should print: 8

    insert_at_head(node, 1);
    insert_at_head(node, 0);
    insert_at_head(node, 11);
    insert_at_head(node, 45);
    insert_at_head(node, 9);
    
    print(node);  // Should print: 9 45 11 0 1 8
    insert_at_end(node,69);
    print(node);

    return 0;
}
