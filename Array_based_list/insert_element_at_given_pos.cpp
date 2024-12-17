#include<iostream>

using namespace std;

void insert_at_pos(int* arr,int pos,int data,int length)
{
    int *temp = arr;

    for(int i = 0; i<length ; i++)
    {
        temp++;
    }
    *temp = data;
    
}
int main(void)
{
    int *arr;
    arr = new int[5];
    arr[0] = 10;
    



    return 0;

}