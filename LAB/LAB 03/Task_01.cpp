#include<iostream>

using namespace std;

int main(void)
{
   int *p = new int (307);

   cout<<"The value is "<<*p;

   delete p;


    return 0;
}