#include <iostream>
using namespace std;

void delete_duplicate(int *arr,int size)
{   int *temp = arr; 
    int *check = arr;
    for(int j = 1; j < size; j++)
    {
    for(int i = 0; i< size; i++)
    {
        if(*check == *temp)
        {
            int *socket = temp;
            socket++;
            temp = socket;
        }
        temp++;
    }
    check++;
    }
}
int main() {
    // Create a dynamic array of size 11
    int size = 11;
    int* dynamicArray = new int[size];

    // Elements to insert
    int elements[] = {58, 26, 91, 70, 70, 91, 58, 58, 58, 66};

    // Insert elements into the dynamic array
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = elements[i]; // Assuming elements have enough values to fill the array
    }

    // Print the elements of the dynamic array
    std::cout << "Dynamic Array Elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    // Free the allocated memory
    delete[] dynamicArray;

    return 0;
}
