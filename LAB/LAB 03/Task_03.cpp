#include<iostream>

using namespace std;

int main(void)
{
    int row,col;

    cout<<"Enter the Row Size "<<endl;
    cin>>row;
    cout<<"Enter the Col Size "<<endl;
    cin>>col;

    int **ptr = new int*[row];

    for(int  i = 0; i < row ; i++)
    {
        ptr[i] = new int [col];
    }
   
    for(int i = 0; i< row; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
           ptr[i][j] = i+j;
        }
    }
    
      for(int i = 0; i< row; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
           cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
    
     for(int j = 0 ; j < row ; j++)
        {
           delete [] ptr[row];
        }
        delete [] ptr;

    return 0 ;
}