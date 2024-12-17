#include <iostream>
using namespace std;

class ArrayList {
private:
    int* list;         // Pointer to dynamically allocated array
    int capacity;      // Maximum capacity of the array
    int size;          // Current number of elements in the array
    int* endPointer;   // Pointer to track the end of the list

public:
    // Constructor: Initialize the list with a given capacity
    ArrayList(int cap) {
        capacity = cap;
        size = 0;
        list = new int[capacity];  // Dynamically allocate memory for the array
        endPointer = list;         // Point to the start of the array
    }

    // Destructor: Free the dynamically allocated memory
    ~ArrayList() {
        delete[] list;
    }

    // 1. Add an element to the end of the list (no index)
    void add(int value) {
        if (size == capacity) {
            // Resize the list if full
            int newCapacity = capacity * 2;
            int* newList = new int[newCapacity];

            // Copy old elements to the new list using pointer
            int* tempPointer = list;
            int* newPointer = newList;
            for (int i = 0; i < size; i++) {
                *newPointer = *tempPointer;
                newPointer++;
                tempPointer++;
            }

            delete[] list;  // Delete the old list
            list = newList;  // Point to the new list
            capacity = newCapacity;  // Update the capacity
            endPointer = list + size;  // Update the end pointer
        }
        *endPointer = value;  // Add the new value to the end
        endPointer++;  // Move the end pointer to the next position
        size++;
    }

    // 2. Insert an element at the beginning of the list (no index)
    void insertAtBeginning(int value) {
        if (size == capacity) {
            // Resize the list if full
            int newCapacity = capacity * 2;
            int* newList = new int[newCapacity];

            // Shift elements to the right using pointers
            int* tempPointer = list;
            int* newPointer = newList + 1;  // Start at position 1
            for (int i = 0; i < size; i++) {
                *newPointer = *tempPointer;
                newPointer++;
                tempPointer++;
            }

            delete[] list;  // Delete the old list
            list = newList;  // Point to the new list
            capacity = newCapacity;  // Update the capacity
            endPointer = list + size;  // Update the end pointer
        }

        // Insert the value at the beginning
        *list = value;
        size++;
        endPointer++;  // Move the end pointer forward
    }

    // 3. Remove an element from the end of the list (no index)
    void remove() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        endPointer--;  // Move the end pointer back
        size--;
    }

    // 4. Get the first element (no index)
    int getFirst() const {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return -1;  // Error value
        }
        return *list;  // Return the first element
    }

    // 5. Get the last element (no index)
    int getLast() const {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return -1;  // Error value
        }
        return *(endPointer - 1);  // Return the last element
    }

    // 6. Check if the list is empty
    bool isEmpty() const {
        return size == 0;
    }

    // 7. Display all elements in the list (using pointers)
    void display() const {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }

        int* tempPointer = list;
        while (tempPointer != endPointer) {
            cout << *tempPointer << " ";
            tempPointer++;
        }
        cout << endl;
    }

    // 8. Get the size of the list (no index)
    int getSize() const {
        return size;
    }

    // 9. Search for an element (return pointer to the element or nullptr)
    int* search(int value) const {
        int* tempPointer = list;
        while (tempPointer != endPointer) {
            if (*tempPointer == value) {
                return tempPointer;  // Return pointer to the element
            }
            tempPointer++;
        }
        return nullptr;  // Not found
    }
};

int main() {
    ArrayList list(5);

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);

    list.display();  // Output: 10 20 30 40 50

    list.add(60);  // Resize the list and add 60
    list.display();  // Output: 10 20 30 40 50 60

    list.insertAtBeginning(5);
    list.display();  // Output: 5 10 20 30 40 50 60

    list.remove();  // Remove last element
    list.display();  // Output: 5 10 20 30 40 50

    cout << "First: " << list.getFirst() << endl;  // Output: First: 5
    cout << "Last: " << list.getLast() << endl;  // Output: Last: 50

    return 0;
}
