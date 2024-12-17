#include<iostream>

using namespace std;
int* rearrange_list(int *arr,int length)
{
   int *first;
   int* second;

   first = arr;
   second = arr + 1;
   while(first <  arr + length && second < arr + length)
   {
   if(*first % 2 == 0 && *second % 2 != 0)       //2,3
   {
    first++;
    second++;
   }

   else if (*first % 2 != 0 && *second % 2 == 0)   //3,2
   {
    
    swap(*first,*second);
    first++;
    second++;
   }

   else if (*first % 2 == 0 && *second % 2 == 0)
   {
      int *temp = second;
      while(1)
      {
        second++;
        if(*second % 2 != 0)
        {
            break;
        }
      }
      swap(*temp,*second);
      second = temp;
      first++;
      second++;
   }
   
   else if (*first % 2 != 0 && *second % 2 != 0)
   {
      int *temp = second;
      while(1)
      {
        second++;
        if(*second % 2 == 0)
        {
            break;
        }
      }
      swap(*temp,*second);
      second = temp;
      first++;
      second++;
   }

   }
   
   return arr;
         
}
int main(void)
{
    int *arr;
    int length = 10;

    arr = new int[length];

  int values[] = {5,2,9,4,7,6,1,3,8,6};  // Hardcoded values
  int* temp = arr;  // Save the original pointer

  for (int i = 0; i < length; i++) {
    *temp = values[i];  // Assign the hardcoded value using pointer dereferencing
    temp++;  // Move to the next element
  }

 temp =  rearrange_list(arr,length);
    for (int i = 0; i < length; i++) {
        cout << *temp++ << " ";  
    }
    
    delete[] arr;
  



    return 0;
}