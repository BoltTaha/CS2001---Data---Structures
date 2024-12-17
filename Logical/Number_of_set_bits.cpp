#include<iostream>

using namespace std;

int main(void)
{
	int a,b;
	int count = 0;
	cin>>a>>b;
	while(a!=0 || b!=0)
	{
	if(a&1)
	{
		count++;
	}
	if(b&1)
	{
		count++;
	}
	
	a = a >> 1;
	b = b >> 1;
}
	cout<<"Total Numbers of set bit in the "<<count;
}
