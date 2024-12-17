#include<iostream>

using namespace std;

int main(void)
{
	int n = 4;
	int i = 1;
	int temp = 0;
	int Row_length = n;
	int Row_length2 = n;
	
	while(i<=n)
	{
		int space = 1;
		while(space<=Row_length - 1)
		{
			cout<<" ";
			//cout<<"Heloooooooooooooooo";
			space++;
		} Row_length--;
	int j = 1;
	while(j<= n-Row_length2 + 1)
	{
		cout<<j;
		j++;
	}
	Row_length2--;
	int k = 1; int Q = i;
	while(k<=n-1)
	{
		if(temp==0)
		{
			cout<<" ";
			
		}
		else
		{
			while(Q-1>0)
			{
				cout<<Q-1;
				Q--;
			}
			int l;
			for(l=0 ; l<n-i ; l++)
			{
				cout<<" ";
			}
			k++;
		}
		temp++;
		
		}
		
		cout<<endl;
		i++;	
		
	}
}
