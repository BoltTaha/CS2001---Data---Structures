#include <iostream>
using namespace std;

class ArrayList {
private:
    int* list;         // Pointer to the dynamic array
    int capacity;      // Maximum size of the array
    int size;          // Current number of elements in the array

public:
    // Constructor
    ArrayList(int cap = 10) : capacity(cap), size(0) {
        list = new int[capacity];
    }

    // Destructor
    ~ArrayList() {
        delete[] list;
    }

    // Check if the list is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Check if the list is full
    bool isFull() const {
        return size == capacity;
    }

    // Insert an element at the end
    void insert(int value) {
        if (isFull()) {
            cout << "List is full. Cannot insert more elements.\n";
            return;
        }
        list[size++] = value;
    }

    // Delete the last element
    void remove() {
        if (isEmpty()) {
            cout << "List is empty. Nothing to remove.\n";
            return;
        }
        size--;
    }

    // Search for an element in the list
    int search(int value) const {
        for (int i = 0; i < size; i++) {
            if (list[i] == value)
                return i; // Return the index of the found element
        }
        return -1; // Element not found
    }

    // Display the elements in the list
    void display() const {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }
        cout << "List elements: ";
        for (int i = 0; i < size; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
    bool resize(int new_size)
    {
        if(new_size < size)
        {
            size = new_size;
            return true;
        }
        if(new_size > size)
        {
            int *temp;
            int *arr_temp;
            arr_temp = new int[new_size];
            temp = arr_temp;
            for(int i = 0; i<size; i++)
            {
                  *temp = *list;
                  temp++;list++;
            }
            list = arr_temp;
            list = new int[new_size];
            
             for(int i = 0; i<size; i++)
            {
                  *list = *temp;
                  temp++;list++;
            }
            return true;
        }

        return false;
    }
};

int main() {
    ArrayList myList(5); // Create an ArrayList with a capacity of 5

    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    myList.insert(40);
    myList.insert(50);
   // myList.insert(50);
   if(myList.resize(6))
   {
    cout<<"resize is done"<<endl;
   }
   else{
    cout<<"resize is not done"<<endl;

   }
   myList.display();
  
  

    return 0;
}
