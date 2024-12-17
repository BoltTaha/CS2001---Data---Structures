#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    // Constructor for easy node creation
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;     // Pointer to the first node (head of the list)

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end
    void insert(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (head == nullptr) {
            head = newNode; // If list is empty, new node becomes the head
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link new node at the end
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to delete a node by value
    void deleteByValue(int value) {
        if (head == nullptr) return; // If list is empty, nothing to delete

        // If the head needs to be deleted
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found in the list!" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Destructor to clean up memory
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void sorted_inserted(int n)
    {    Node* new_Node =  new Node(n);

        if(head == NULL)
        {
            head = new_Node;
            return;
        }

        Node* temp = head;
        bool check = check_for_linked_is_ascending();
         Node* prev = NULL;
        if(check)
        {
            //asceding order
           
        }
        else
        {

            //descnding order
          while(temp!= NULL)
          {
            if(temp->data > n)
            { prev = temp;
              temp = temp->next;
              continue;
            }
            if(temp->data <= n)
            {
                prev->next = new_Node;
                new_Node->next = temp;
            }

           
          }
          if(temp == NULL)
          {
            prev->next = new_Node;
          }
        }

        
    }
    bool check_for_linked_is_ascending()
    {
        if(head == NULL)
        {
            return true; // for ascending
        }
        Node* temp = head;
        
             if(temp->next != NULL && temp->data < temp->next->data )
             {
                return true;  //asscending order hai
             }
             else if(temp->next == NULL)
             {
                return true; //eik node bhia scedning order hai
             }
             else
             {
                return false;
             }
        
    }
};

// Main function to demonstrate the linked list
int main() {
    LinkedList list;

    // Inserting elements
    list.insert(15);
    list.insert(11);
    list.insert(9);
    list.insert(5);
    list.insert(3);

    // Displaying the list
    cout << "Linked List: ";
    list.display();

    
    // Displaying the updated list
    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
