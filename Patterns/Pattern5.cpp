#include<iostream>
using namespace std;

int main(void)
{
	int n;
	char alp = 'A';
	
	cout<<"Enter the size for the rows and col "<<endl;
	cin>>n;
	
	int i = 1;
	
	while(i<=n)
	{
		int j = 1;
		while(j<=n)
		{
			cout<<alp<<" ";
			j++;
		}
		alp++;
		cout<<endl;
		i++;
		
	}
}
