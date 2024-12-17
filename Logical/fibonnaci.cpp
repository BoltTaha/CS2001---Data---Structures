#include<iostream>
using namespace std;

int fibonnaci(int n)
{
	int i;
	int first = 0;
	int second = 1;
	int last;
	for(i = 2; i<n ; i++)
	{
		last = first + second;
		first = second;
		second = last;
	}
	return last;
}
int main(void)
{
	int n;
	cin>>n;
	cout<<fibonnaci(n);
	return 0;
}
