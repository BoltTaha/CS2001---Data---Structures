#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    // Key not found
    return -1;
}

int main(void)
{
    int even[6] = {2, 4, 6, 8, 10, 12};
    int odd[6] = {3, 5, 7, 9, 11, 13};

    int size = sizeof(even) / sizeof(int);

    // Searching for the key 13 in the 'odd' array
    int index = BinarySearch(odd, size, 13);

    if (index != -1)
    {
        cout << "Key found at index: " << index << endl;
    }
    else
    {
        cout << "Key not found." << endl;
    }

    return 0;
}
