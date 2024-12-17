#include<iostream>

using namespace std;

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main(void)
{
	int a,b;
	cout<<"Enter the First Number "<<endl;
	cin>>a;
	cout<<"Enter the 2nD Number "<<endl;
	cin>>b;
	swap(&a,&b);
	cout<<"The Values after Swap are "<<endl;
	cout<<"A "<<a<<endl;
	cout<<"B "<<b<<endl;

	
	return 0;
}
