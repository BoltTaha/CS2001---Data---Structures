#include<iostream>

using namespace std;

int main(void)
{
	int i = 1;
	int n = 5;
	int t = n;
	
	while(i<=n)
	{
		int j = 1;
		while(j<=i)
		{
			if(j==i)
			{
				cout<<"1";
			}
			else{
			
			if(i%2==0 && j%2==0 || i==n && j==1)
			{
				cout<<"1";
			}
			else{
				cout<<"*";
			}
		}
		j++;
		}
	int k = 1;
	while(k<=n-i)
	{
		if(t%2!=0)
		{
			t--;
		}
		if(k==t)
		{
			cout<<"1";
			t--;
		}
		else{
			cout<<"*";
		}
		k++;
		}	
		cout<<endl;
		i++;
	}
}
