#include<iostream>

using namespace std;

int main(void)
{
	int i = 1;
	int n = 5;
	int start = 1;
	int l = n;
	int t = n;
	
	
	while(i<=n)
	{
		int j = 1;
		while(j<=n-i+1)
		{
			cout<<j;
			j++;
		}
	start = i - 1;
	while(start)
	{
		cout<<"*";
		start--;
	}
	
	int k = 1;
	while(k<=i-1)
	{
	  cout<<"*";
	  t--;
	  k++;	
	}	
	
	int l = 1;
	
	int check = n - i + 1;
	while(l<=n-i+1)
	{
		cout<<check;
		check--;
		l++;
	}
		
		
		cout<<endl;
		i++;
	}
}
