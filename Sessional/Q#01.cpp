#include<iostream>

using namespace std;


int * rearrange(int* arr,int length)
{
    int* first = arr;
    int * second = arr + 1;

    while(second < arr + length)
    {
   
        if(*first > 0 && *second < 0 )
        {
            first = first + 2;
            second = second + 2;

        }

        else if(*first > 0 && *second > 0)
        {
            int* temp = second;
            while ( 1 )
            {
                second++;
                if(*second < 0)
                {
                    break;
                }
            }
            swap(*temp,*second);
            second = temp;
            first = first + 2;
            second = second + 2;
            
        }

        else if(*first < 0 && *second < 0)
        {
            int* temp = first;
            while ( 1 )
            {
                first++;
                if(*first > 0)
                {
                    break;
                }
            }
            swap(*temp,*first);
            first = temp;
            first = first + 2;
            second = second + 2;
            
        }

        else if(*first < 0 && *second > 0)
        {
            swap(*first, *second);
            first = first + 2;
            second = second + 2;
        }
    }

    return arr;
}



int main() {
    int arr[] = {4, 2, -1, 5, -3, -6};
    //int arr[] = {7, -2, 3, -8, 1, -4};  
  //int arr[] = {9, -3, -5, 2, -7, 1};  
//   int arr[] = {-11,10,6,1,-9,-5};
   // int arr[] = {-1,-2,10,20,9,-8};






    int length = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, length);

    // Print the rearranged array
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}