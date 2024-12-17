#include<iostream>

using namespace std;

int main(void)
{
	int n;
	cout<<"Enter the NUmber"<<endl;
	cin>>n;
	
	int count = 0;
	while(n!=0)
	{  if(n==1)
	{
	break;
		
	}
		if(n&1)
		{
			count++;
		}
		n = n >>1;
	}
	if(count==1)
	{
		cout<<"Power of 2"<<endl;
	}
	else
	{
		cout<<"Not a power of two"<<endl;
	}
}
