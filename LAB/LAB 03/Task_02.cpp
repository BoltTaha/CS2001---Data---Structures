#include<iostream>

using namespace std;

int main(void)
{
    cout<<"Enter the Size for the Array "<<endl;
    int n;
    cin>>n;

    int *arr = new int[n];

    for(int i  = 0; i < n ; i++)
    {
        // *arr = 1;
        // arr++;
        arr[i] = i + 1;
    }
   
      for(int i  = 0; i < n ; i++)
    {
        // *arr = 1;
        // arr++;
       cout<<"The Element in the Array are " <<arr[i]<<endl;
    }
    
      delete [] arr;
}