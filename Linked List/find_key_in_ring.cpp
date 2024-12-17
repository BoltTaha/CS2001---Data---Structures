#include<iostream>
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
 
 void find_elment(Node* head,int key)
 {
    Node* slow = head;
    Node* fast = head;
    while(fast->next !=head && fast->next->next != head)
    {
        slow  = slow->next;
        fast = fast->next->next;
    }
    while(head!=slow)
    {
        if(head->data == key)
        {
            cout<<"The ket element find in the first half"<<endl;
            return;
        }
        head = head->next;
        
    }

     while(slow!=head)
    {
        if(slow->data == key)
        {
            cout<<"The ket element find in the 2nd half"<<endl;
            return;
        }
        slow= slow->next;
        
    }

 }
void insert_at_head(Node* &tail, int data) {
    Node* node = new Node(data);
    
    if (tail == NULL) {
        // If the list is empty, make the new node point to itself
        tail = node;
        tail->next = tail; 
    } else {
        // Insert the new node at the head
        node->next = tail->next;  // New node points to the current head
        tail->next = node;        // Tail now points to the new head
    }
}

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


int main(void)
{
   Node* node = NULL;  // Initialize the tail pointer to NULL

    insert_at_head(node, 8);
    //print(node);  // Should print: 8

    insert_at_head(node, 1);
    insert_at_head(node, 0);
    insert_at_head(node, 11);
    insert_at_head(node, 45);
    insert_at_head(node, 9);
    
    print(node);  // Should print: 9 45 11 0 1 8

    find_elment(node,45);


    return 0;
}